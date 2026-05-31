#include "FactorNeutralizer.hpp"

std::vector<double>
FactorNeutralizer::demean(
    const std::vector<double>& values
) const
{
    double mean = 0.0;

    for(double x : values)
    {
        mean += x;
    }

    mean /= values.size();

    std::vector<double> result;

    for(double x : values)
    {
        result.push_back(
            x - mean
        );
    }

    return result;
}