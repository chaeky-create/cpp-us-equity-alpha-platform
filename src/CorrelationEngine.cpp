#include "CorrelationEngine.hpp"

#include <cmath>

double CorrelationEngine::correlation(
    const std::vector<double>& x,
    const std::vector<double>& y
) const
{
    if (x.size() != y.size() || x.empty())
        return 0.0;

    double mean_x = 0.0;
    double mean_y = 0.0;

    for (size_t i = 0; i < x.size(); ++i)
    {
        mean_x += x[i];
        mean_y += y[i];
    }

    mean_x /= x.size();
    mean_y /= y.size();

    double cov = 0.0;
    double var_x = 0.0;
    double var_y = 0.0;

    for (size_t i = 0; i < x.size(); ++i)
    {
        double dx = x[i] - mean_x;
        double dy = y[i] - mean_y;

        cov += dx * dy;
        var_x += dx * dx;
        var_y += dy * dy;
    }

    return cov / std::sqrt(var_x * var_y);
}