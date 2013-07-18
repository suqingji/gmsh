#include "QuadNodeBasis.h"
#include "QuadReferenceSpace.h"
#include "Legendre.h"

using namespace std;

QuadNodeBasis::QuadNodeBasis(size_t order){
  // Reference Space //
  refSpace  = new QuadReferenceSpace;
  const size_t nRefSpace = getReferenceSpace().getNReferenceSpace();

  const vector<vector<vector<size_t> > >&
    edgeIdx = refSpace->getEdgeNodeIndex();

  const vector<vector<vector<size_t> > >&
    faceIdx = refSpace->getFaceNodeIndex();

  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 2;

  nVertex   = 4;
  nEdge     = 4 * (order - 1);
  nFace     =     (order - 1) * (order - 1);
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Legendre Polynomial //
  Polynomial* legendre = new Polynomial[order];
  Legendre::integrated(legendre, order);

  // Lagrange & Lifting //
  const Polynomial lagrange[4] =
    {
      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
                 (Polynomial(1, 0, 1, 0)))
    };

  const Polynomial lifting[4] =
    {
      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0))),

      Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
                 (Polynomial(1, 0, 1, 0)))
    };

  // Basis //
  basis = new Polynomial**[nRefSpace];

  for(size_t s = 0; s < nRefSpace; s++)
    basis[s] = new Polynomial*[nFunction];

  // Vertex Based //
  for(size_t s = 0; s < nRefSpace; s++){
    basis[s][0] = new Polynomial(lagrange[0]);
    basis[s][1] = new Polynomial(lagrange[1]);
    basis[s][2] = new Polynomial(lagrange[2]);
    basis[s][3] = new Polynomial(lagrange[3]);
  }

  // Edge Based //
  for(size_t s = 0; s < nRefSpace; s++){
    size_t i = nVertex;

    for(size_t e = 0; e < 4; e++){
      for(size_t l = 1; l < order; l++){
        basis[s][i] =
          new Polynomial(legendre[l].compose(lifting[edgeIdx[s][e][1]] -
                                             lifting[edgeIdx[s][e][0]])
                         *
                         (lagrange[edgeIdx[s][e][0]] +
                          lagrange[edgeIdx[s][e][1]]));

        i++;
      }
    }
  }

  // Face Based //

  // NB: We use (*(*faceIdx[s])[f])[]
  //     where f = 0, because triangles
  //     have only ONE face: the face '0'

  for(size_t s = 0; s < nRefSpace; s++){
    size_t i = nVertex + nEdge;

    for(size_t l1 = 1; l1 < order; l1++){
      for(size_t l2 = 1; l2 < order; l2++){
       basis[s][i] =
         new Polynomial(legendre[l1].compose(lifting[faceIdx[s][0][0]] -
                                             lifting[faceIdx[s][0][1]])
                         *

                        legendre[l2].compose(lifting[faceIdx[s][0][0]] -
                                             lifting[faceIdx[s][0][3]]));

        i++;
      }
    }
  }

  // Mapping to Gmsh Quad //
  // x = (u + 1) / 2
  // y = (v + 1) / 2
  //
  // (x, y) = Zaglmayr Ref Quad
  // (u, v) = Gmsh     Ref Quad

  Polynomial  mapX(Polynomial(0.5, 1, 0, 0) +
                   Polynomial(0.5, 0, 0, 0));

  Polynomial  mapY(Polynomial(0.5, 0, 1, 0) +
                   Polynomial(0.5, 0, 0, 0));

  for(size_t s = 0; s < nRefSpace; s++){
    for(size_t i = 0; i < nFunction; i++){
      Polynomial* tmp;
      tmp = basis[s][i];
      basis[s][i] = new Polynomial(tmp->compose(mapX, mapY));
      delete tmp;
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
}

QuadNodeBasis::~QuadNodeBasis(void){
  const size_t nRefSpace = getReferenceSpace().getNReferenceSpace();

  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(size_t i = 0; i < nRefSpace; i++){
    for(size_t j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
