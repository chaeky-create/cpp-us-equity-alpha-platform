#pragma once

#include <vector>

class SignalCombiner
{
public:
    std::vector<double> zscore(
        const std::vector<double>& values
    ) const;

    std::vector<double> combine(
        const std::vector<double>& signal_a,
        const std::vector<double>& signal_b,
        double weight_a,
        double weight_b
    ) const;
};