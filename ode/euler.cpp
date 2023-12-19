#include <vector>
#include <functional>
#include <fstream>

using Vec = std::vector<double>;

std::vector<Vec> euler_explicit(std::function<Vec(Vec, double)> f,
                                std::vector<double> times,
                                std::vector<double> x_init)
{
  std::vector<Vec> solution(times.size());
  solution[0] = x_init;
  int nb_unknown = x_init.size();
  for (int i = 1; i < times.size(); i++)
  {
    const double dt = (times[i] - times[i - 1]);
    auto dxdt = f(solution[i - 1], times[i - 1]);
    solution[i].resize(nb_unknown);
    for (int j = 0; j < nb_unknown; j++)
    {
      solution[i][j] = solution[i - 1][j] + dt * dxdt[j];
    }
  }
  return solution;
}

void write_solution(std::vector<Vec> solution, const std::string &fname)
{
  std::ofstream out(fname, std::ios::app);
  for (auto &row : solution)
  {
    for (auto &x : row)
    {
      out << x << " ";
    }
    out << std::endl;
  }
  out.close();
}