#pragma once

#include <vector>

class FactorNeutralizer
{
public:

    std::vector<double>
    demean(
        const std::vector<double>& values
    ) const;
};