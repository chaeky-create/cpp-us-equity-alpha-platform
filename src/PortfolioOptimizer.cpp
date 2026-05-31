#include "PortfolioOptimizer.hpp"

std::vector<double>
PortfolioOptimizer::equalWeight(
    int n_assets
) const
{
    return std::vector<double>(
        n_assets,
        1.0 / n_assets
    );
}

std::vector<double>
PortfolioOptimizer::inverseVolWeight(
    const std::vector<double>& vols
) const
{
    std::vector<double> weights;

    double total = 0.0;

    for(double v : vols)
        total += 1.0 / v;

    for(double v : vols)
        weights.push_back(
            (1.0 / v) / total
        );

    return weights;
}