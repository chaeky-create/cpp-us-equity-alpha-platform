#include "SignalCombiner.hpp"

#include <cmath>

std::vector<double>
SignalCombiner::zscore(
    const std::vector<double>& values
) const
{
    std::vector<double> result;

    double mean = 0.0;

    for (double x : values)
        mean += x;

    mean /= values.size();

    double variance = 0.0;

    for (double x : values)
        variance += (x - mean) * (x - mean);

    variance /= values.size();

    double sd = std::sqrt(variance);

    for (double x : values)
        result.push_back((x - mean) / sd);

    return result;
}

std::vector<double>
SignalCombiner::combine(
    const std::vector<double>& signal_a,
    const std::vector<double>& signal_b,
    double weight_a,
    double weight_b
) const
{
    std::vector<double> combined;

    for (size_t i = 0; i < signal_a.size(); ++i)
    {
        combined.push_back(
            weight_a * signal_a[i]
            +
            weight_b * signal_b[i]
        );
    }

    return combined;
}