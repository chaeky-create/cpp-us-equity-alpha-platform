#pragma once

#include <vector>

class MeanVarianceOptimizer
{
public:

    std::vector<double> optimize(
        const std::vector<double>& expected_returns,
        const std::vector<double>& variances
    ) const;
};