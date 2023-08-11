#include <Rcpp.h>
#include <RcppNumerical.h>

using namespace Numer;

// Implémentation de la fonction d'évaluation de l'EDP de diffusion
class DiffusionPde : public PdeModel
{
public:
  // Méthode pour évaluer la diffusion
  double diffusion(const double& x, const double& t, const double& u) const
  {
    return 0.1; // Coefficient de diffusion constant
  }

  // Méthode pour évaluer les conditions aux limites
  double boundary(const double& x, const double& t) const
  {
    if (x == 0 || x == 1)
      return 0; // Conditions de Dirichlet homogènes
    else
      return NA_REAL; // Conditions non spécifiées
  }
};

// Fonction pour résoudre l'EDP de diffusion
// nx : nombre de points d'échantillonnage sur l'axe x
// nt : nombre de points d'échantillonnage sur l'axe t
// T : temps final
// Retourne une matrice représentant la solution de l'EDP
NumericMatrix solveDiffusionPde(int nx, int nt, double T)
{
  // Création de la classe du modèle de l'EDP
  DiffusionPde pde;

  // Création de l'objet de résolution de l'EDP
  PdeSolver solver(pde, nx, nt, T);

  // Résolution de l'EDP de diffusion
  NumericMatrix solution = solver.solve();

  // Retourner la solution
  return solution;
}