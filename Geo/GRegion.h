// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GREGION_H_
#define _GREGION_H_

#include <list>
#include <string>
#include <vector>
#include <stdio.h>
#include "GEntity.h"
#include "boundaryLayersData.h"

class MElement;
class MTetrahedron;
class MHexahedron;
class MPrism;
class MPyramid;
class MPolyhedron;
class MTrihedron;
class ExtrudeParams;
class BoundaryLayerColumns;

// A model region.
class GRegion : public GEntity {
protected:
  std::vector<GFace *> l_faces;
  std::vector<GVertex *> embedded_vertices;
  std::vector<GFace *> embedded_faces;
  std::vector<GEdge *> embedded_edges;
  std::vector<int> l_dirs;
  BoundaryLayerColumns _columns;

public:
  GRegion(GModel *model, int tag);
  virtual ~GRegion();

  // delete mesh data
  virtual void deleteMesh(bool onlyDeleteElements = false);

  // get the dimension of the region (3)
  virtual int dim() const { return 3; }

  // returns the parent entity for partitioned entities
  virtual GEntity *getParentEntity() { return 0; }

  // set the visibility flag
  virtual void setVisibility(char val, bool recursive = false);

  // set color
  virtual void setColor(unsigned int val, bool recursive = false);

  // add embedded vertices/edges/faces
  void addEmbeddedVertex(GVertex *v) { embedded_vertices.push_back(v); }
  void addEmbeddedEdge(GEdge *e) { embedded_edges.push_back(e); }
  void addEmbeddedFace(GFace *f) { embedded_faces.push_back(f); }

  // get/set faces that bound the region
  int delFace(GFace *face);

  virtual std::vector<GFace *> faces() const { return l_faces; }

  virtual std::vector<int> faceOrientations() const { return l_dirs; }
  void set(std::vector<GFace *> const f) { l_faces = f; }
  void setOrientations(std::vector<int> f) { l_dirs = f; }
  void setFace(GFace *const f, int const orientation)
  {
    l_faces.push_back(f);
    l_dirs.push_back(orientation);
  }

  // vertices that are embedded in the region
  virtual std::vector<GVertex *> &embeddedVertices()
  {
    return embedded_vertices;
  }
  // edges that are embedded in the region
  virtual std::vector<GEdge *> embeddedEdges() const { return embedded_edges; }
  virtual std::vector<GEdge *> &embeddedEdges() { return embedded_edges; }
  // faces that are embedded in the region
  virtual std::vector<GFace *> embeddedFaces() const { return embedded_faces; }

  // edges that bound the region
  virtual std::vector<GEdge *> edges() const;

  // vertices that bound the region
  virtual std::vector<GVertex *> vertices() const;

  // get the bounding box
  virtual SBoundingBox3d bounds(bool fast = false) const;

  // get the oriented bounding box
  virtual SOrientedBoundingBox getOBB();

  // check if the region is connected to another region by an edge
  bool edgeConnected(GRegion *r) const;

  // compute volume, moment of intertia and center of gravity
  double computeSolidProperties(std::vector<double> cg,
                                std::vector<double> inertia);

  // return a type-specific additional information string
  virtual std::string getAdditionalInfoString(bool multline = false);

  // export in GEO format
  virtual void writeGEO(FILE *fp);

  // number of types of elements
  int getNumElementTypes() const { return 6; }

  // get total/by-type number of elements in the mesh
  size_type getNumMeshElements() const;
  unsigned int getNumMeshElementsByType(const int familyType) const;
  unsigned int getNumMeshParentElements();
  void getNumMeshElements(unsigned *const c) const;

  // get the start of the array of a type of element
  MElement *const *getStartElementType(int type) const;

  // get the element at the given index
  MElement *getMeshElement(unsigned int index) const;
  // get the element at the given index for a given familyType
  MElement *getMeshElementByType(const int familyType,
                                 const unsigned int index) const;

  // reset the mesh attributes to default values
  virtual void resetMeshAttributes();

  struct {
    // do we recombine the tetrahedra of the mesh into hex?
    int recombine3D;
    // is this surface meshed using a transfinite interpolation
    char method;
    // the extrusion parameters (if any)
    ExtrudeParams *extrude;
    // corners of the transfinite interpolation
    std::vector<GVertex *> corners;
    // structured/unstructured coupling using pyramids
    int QuadTri;
  } meshAttributes;

  // a array for accessing the transfinite vertices using a triplet of
  // indices
  std::vector<std::vector<std::vector<MVertex *> > > transfinite_vertices;

  std::vector<MTetrahedron *> tetrahedra;
  std::vector<MHexahedron *> hexahedra;
  std::vector<MPrism *> prisms;
  std::vector<MPyramid *> pyramids;
  std::vector<MTrihedron *> trihedra;
  std::vector<MPolyhedron *> polyhedra;

  void addTetrahedron(MTetrahedron *t) { tetrahedra.push_back(t); }
  void addHexahedron(MHexahedron *h) { hexahedra.push_back(h); }
  void addPrism(MPrism *p) { prisms.push_back(p); }
  void addPyramid(MPyramid *p) { pyramids.push_back(p); }
  void addPolyhedron(MPolyhedron *p) { polyhedra.push_back(p); }
  void addTrihedron(MTrihedron *t) { trihedra.push_back(t); }
  void addElement(int type, MElement *e);
  void removeElement(int type, MElement *e);

  // get the boundary layer columns
  BoundaryLayerColumns *getColumns() { return &_columns; }

  virtual bool reorder(const int elementType, const std::vector<int> &ordering);

  // set the reverseMesh constraint in the bounding surfaces so that the
  // boundary mesh has outward pointing normals, based on the STL triangulation
  bool setOutwardOrientationMeshConstraint();
};

#endif
