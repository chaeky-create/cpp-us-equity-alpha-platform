#pragma once

#include <vector>

struct BacktestResult {
    std::vector<double> daily_returns;
    double cumulative_return = 0.0;
};