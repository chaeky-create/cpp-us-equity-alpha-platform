#include "Backtester.hpp"

#include <cmath>

static double mean(const std::vector<double>& returns) {
    double sum = 0.0;
    for (double r : returns) sum += r;
    return returns.empty() ? 0.0 : sum / returns.size();
}

static double volatility(const std::vector<double>& returns) {
    if (returns.size() < 2) return 0.0;

    double avg = mean(returns);
    double var = 0.0;

    for (double r : returns) {
        var += (r - avg) * (r - avg);
    }

    var /= static_cast<double>(returns.size() - 1);
    return std::sqrt(var);
}

static double max_drawdown(const std::vector<double>& returns) {
    double equity = 1.0;
    double peak = 1.0;
    double max_dd = 0.0;

    for (double r : returns) {
        equity *= (1.0 + r);
        if (equity > peak) peak = equity;

        double dd = (equity / peak) - 1.0;
        if (dd < max_dd) max_dd = dd;
    }

    return max_dd;
}

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

    double daily_mean = mean(returns);
    double daily_vol = volatility(returns);

    result.annual_return = std::pow(1.0 + result.cumulative_return, 252.0 / returns.size()) - 1.0;
    result.annual_volatility = daily_vol * std::sqrt(252.0);
    result.sharpe_ratio = daily_vol == 0.0 ? 0.0 : daily_mean / daily_vol * std::sqrt(252.0);
    result.max_drawdown = max_drawdown(returns);

    return result;
}