#include <iostream>
#include <vector>

#include "euler.hpp"

int main(int argc, char **argv)
{

  if (argc != 2)
  {
    std::cerr << "Error" << std::endl;
    return EXIT_FAILURE;
  }

  const int n_step = std::atoi(argv[1]);

  const double alpha = 2. / 3.;
  const double beta = 4. / 3.;
  const double delta = 1.;
  const double gamma = 1.;

  const double t_init = 0;
  const double t_end = 20.;

  // 1. Définir discrétisation en temps
  std::vector<double> times(n_step);
  times[0] = t_init;
  const double dt = (t_end - t_init) / n_step;
  for (int i = 1; i < n_step; i++)
  {
    times[i] = times[i - 1] + dt;
  }
  // 2. Définir le système à résoudre
  auto f = [alpha, beta, delta, gamma](std::vector<double> x, double t)
  {
    std::vector<double> dxdt(2);
    dxdt[0] = alpha * x[0] - beta * x[0] * x[1];
    dxdt[1] = delta * x[0] * x[1] - gamma * x[1];
    return dxdt;
  };

  // 3. Définir un état initial
  std::vector<double> x_init{2., 2.};

  // 4. Résoudre
  auto sol = euler_explicit(f, times, x_init);

  // 5. Sauvegarder

  write_solution(sol, "output.txt");

  return EXIT_SUCCESS;
}