#include "MeanVarianceOptimizer.hpp"

std::vector<double>
MeanVarianceOptimizer::optimize(
    const std::vector<double>& expected_returns,
    const std::vector<double>& variances
) const
{
    std::vector<double> raw;

    double total = 0.0;

    for(size_t i=0;i<expected_returns.size();i++)
    {
        double score =
            expected_returns[i]
            /
            variances[i];

        raw.push_back(score);

        total += score;
    }

    for(double& w : raw)
    {
        w /= total;
    }

    return raw;
}