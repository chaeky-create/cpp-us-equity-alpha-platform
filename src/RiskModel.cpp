#include "RiskModel.hpp"

double RiskModel::covariance(
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

    for (size_t i = 0; i < x.size(); ++i)
    {
        cov +=
            (x[i] - mean_x)
            *
            (y[i] - mean_y);
    }

    return cov / x.size();
}