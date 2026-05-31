#include "Backtester.hpp"

BacktestResult Backtester::run(
    const std::vector<double>& returns
) const {
    BacktestResult result;

    result.daily_returns = returns;

    double cumulative = 1.0;

    for (double r : returns) {
        cumulative *= (1.0 + r);
    }

    result.cumulative_return = cumulative - 1.0;

    return result;
}