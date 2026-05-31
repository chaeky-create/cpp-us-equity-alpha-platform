#include "FactorEngine.hpp"

#include <limits>

std::vector<double> FactorEngine::momentum(const std::vector<PriceBar>& data, int lookback_days) const {
    std::vector<double> factor(data.size(), std::numeric_limits<double>::quiet_NaN());

    for (std::size_t i = static_cast<std::size_t>(lookback_days); i < data.size(); ++i) {
        const double past_price = data[i - static_cast<std::size_t>(lookback_days)].adjusted_close;
        const double current_price = data[i].adjusted_close;

        if (past_price > 0.0) {
            factor[i] = (current_price / past_price) - 1.0;
        }
    }

    return factor;
}

std::vector<double> FactorEngine::reversal(const std::vector<PriceBar>& data, int lookback_days) const {
    std::vector<double> factor = momentum(data, lookback_days);

    for (double& value : factor) {
        value = -value;
    }

    return factor;
}