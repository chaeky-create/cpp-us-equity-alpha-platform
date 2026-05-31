#pragma once

#include <vector>

struct BacktestResult {
    std::vector<double> daily_returns;

    double cumulative_return = 0.0;
    double annual_return = 0.0;
    double annual_volatility = 0.0;
    double sharpe_ratio = 0.0;
    double max_drawdown = 0.0;
};