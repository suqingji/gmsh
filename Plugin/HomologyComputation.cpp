// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Matti Pellikka <matti.pellikka@tut.fi>.

#include <stdlib.h>
#include "Gmsh.h"
#include "GmshConfig.h"
#include "GModel.h"
#include "Homology.h"
#include "HomologyComputation.h"

#if defined(HAVE_KBIPACK)

StringXNumber HomologyComputationOptions_Number[] = {
  {GMSH_FULLRC, "PhysicalGroupForDomain1", NULL, 0.},
  {GMSH_FULLRC, "PhysicalGroupForDomain2", NULL, 0.},
  {GMSH_FULLRC, "PhysicalGroupForSubdomain1", NULL, 0.},
  {GMSH_FULLRC, "PhysicalGroupForSubdomain2", NULL, 0.},
  {GMSH_FULLRC, "CompututeHomology", NULL, 1.},
  {GMSH_FULLRC, "ComputeCohomology", NULL, 0.},
};

StringXString HomologyComputationOptions_String[] = {
  {GMSH_FULLRC, "Filename", NULL, "homology.msh"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterHomologyComputationPlugin()
  {
    return new GMSH_HomologyComputationPlugin();
  }
}

std::string GMSH_HomologyComputationPlugin::getHelp() const
{
  return "Plugin(Homology) computes ranks and basis elements "
    "of (relative) homology and cohomology spaces.\n\n"

    "Define physical groups in order to specify the computation "
    "domain and the relative subdomain. Otherwise the whole mesh "
    "is the domain and the relative subdomain is empty. \n\n"

    "Plugin(Homology) creates new views, one for each basis element. "
    "The resulting basis chains together with the mesh are saved to "
    "the file given.";
}

int GMSH_HomologyComputationPlugin::getNbOptions() const
{
  return sizeof(HomologyComputationOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_HomologyComputationPlugin::getOption(int iopt)
{
  return &HomologyComputationOptions_Number[iopt];
}

int GMSH_HomologyComputationPlugin::getNbOptionsStr() const
{
  return sizeof(HomologyComputationOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_HomologyComputationPlugin::getOptionStr(int iopt)
{
  return &HomologyComputationOptions_String[iopt];
}

PView *GMSH_HomologyComputationPlugin::execute(PView *v)
{
  std::string fileName = HomologyComputationOptions_String[0].def;

  std::vector<int> domain;
  std::vector<int> subdomain;

  int d1 = (int)HomologyComputationOptions_Number[0].def;
  int d2 = (int)HomologyComputationOptions_Number[1].def;
  if(d1 > 0) domain.push_back(d1);
  if(d2 > 0) domain.push_back(d2);
  d1 = (int)HomologyComputationOptions_Number[2].def;
  d2 = (int)HomologyComputationOptions_Number[3].def;
  if(d1 > 0) subdomain.push_back(d1);
  if(d2 > 0) subdomain.push_back(d2);


  int hom = (int)HomologyComputationOptions_Number[4].def;
  int coh = (int)HomologyComputationOptions_Number[5].def;

  GModel *m = GModel::current();

  Homology* homology = new Homology(m, domain, subdomain);
  homology->setFileName(fileName);
  CellComplex* cc = homology->createCellComplex();
  if(hom != 0){
    homology->findHomologyBasis(cc);
  }
  if(coh != 0){
    cc->restoreComplex();
    homology->findCohomologyBasis(cc);
  }

  delete cc;
  delete homology;

  return 0;
}

#endif
