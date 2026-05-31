#pragma once

#include <vector>

class RiskModel {
public:

    double covariance(
        const std::vector<double>& x,
        const std::vector<double>& y
    ) const;
};