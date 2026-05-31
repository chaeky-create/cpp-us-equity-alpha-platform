#include "PerformanceMetrics.hpp"

#include <cmath>
#include <limits>

double PerformanceMetrics::mean(const std::vector<double>& returns) const {
    if (returns.empty()) {
        return 0.0;
    }

    double sum = 0.0;

    for (const double r : returns) {
        sum += r;
    }

    return sum / static_cast<double>(returns.size());
}

double PerformanceMetrics::volatility(const std::vector<double>& returns) const {
    if (returns.size() < 2) {
        return 0.0;
    }

    const double avg = mean(returns);
    double variance = 0.0;

    for (const double r : returns) {
        variance += (r - avg) * (r - avg);
    }

    variance /= static_cast<double>(returns.size() - 1);

    return std::sqrt(variance);
}

double PerformanceMetrics::sharpe_ratio(const std::vector<double>& returns, double risk_free_rate) const {
    const double daily_mean = mean(returns);
    const double daily_vol = volatility(returns);

    if (daily_vol == 0.0) {
        return 0.0;
    }

    const double excess_daily_return = daily_mean - (risk_free_rate / 252.0);

    return std::sqrt(252.0) * excess_daily_return / daily_vol;
}

double PerformanceMetrics::max_drawdown(const std::vector<double>& returns) const {
    double equity = 1.0;
    double peak = 1.0;
    double max_dd = 0.0;

    for (const double r : returns) {
        equity *= (1.0 + r);

        if (equity > peak) {
            peak = equity;
        }

        const double drawdown = (equity / peak) - 1.0;

        if (drawdown < max_dd) {
            max_dd = drawdown;
        }
    }

    return max_dd;
}