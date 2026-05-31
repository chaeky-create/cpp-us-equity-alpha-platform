#pragma once

#include <vector>

class PortfolioRebalancer
{
public:

    double turnover(
        const std::vector<double>& old_weights,
        const std::vector<double>& new_weights
    ) const;
};