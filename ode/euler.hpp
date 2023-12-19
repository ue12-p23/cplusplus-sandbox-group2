#pragma once

#include <vector>
#include <functional>

using Vec = std::vector<double>;

std::vector<Vec> euler_explicit(std::function<Vec(Vec, double)> f,
                                std::vector<double> times,
                                std::vector<double> x_init);

void write_solution(std::vector<Vec> solution, const std::string &fname);