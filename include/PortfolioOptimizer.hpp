#pragma once

#include <vector>

class PortfolioOptimizer {
public:

    std::vector<double> equalWeight(
        int n_assets
    ) const;

    std::vector<double> inverseVolWeight(
        const std::vector<double>& vols
    ) const;
};