#pragma once

#include <vector>

class PerformanceMetrics {
public:
    double mean(const std::vector<double>& returns) const;
    double volatility(const std::vector<double>& returns) const;
    double sharpe_ratio(const std::vector<double>& returns, double risk_free_rate = 0.0) const;
    double max_drawdown(const std::vector<double>& returns) const;
};