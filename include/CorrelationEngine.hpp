#pragma once

#include <vector>

class CorrelationEngine {
public:
    double correlation(
        const std::vector<double>& x,
        const std::vector<double>& y
    ) const;
};