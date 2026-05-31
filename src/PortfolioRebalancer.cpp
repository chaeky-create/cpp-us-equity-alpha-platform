#include "PortfolioRebalancer.hpp"

#include <cmath>

double
PortfolioRebalancer::turnover(
    const std::vector<double>& old_weights,
    const std::vector<double>& new_weights
) const
{
    double total = 0.0;

    for(size_t i=0;i<old_weights.size();i++)
    {
        total += std::abs(
            new_weights[i]
            -
            old_weights[i]
        );
    }

    return total;
}