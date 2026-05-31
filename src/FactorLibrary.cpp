#include "FactorLibrary.hpp"

#include <cmath>

std::vector<double>
FactorLibrary::momentum(
    const std::vector<double>& prices,
    int lookback
) const {
    std::vector<double> result(
        prices.size(),
        0.0
    );

    for (size_t i = lookback; i < prices.size(); ++i) {
        result[i] =
            prices[i] /
            prices[i - lookback]
            - 1.0;
    }

    return result;
}

std::vector<double>
FactorLibrary::mean_reversion(
    const std::vector<double>& prices,
    int lookback
) const {
    std::vector<double> result(
        prices.size(),
        0.0
    );

    for (size_t i = lookback; i < prices.size(); ++i) {
        result[i] =
            -(prices[i] /
            prices[i - lookback]
            - 1.0);
    }

    return result;
}

std::vector<double>
FactorLibrary::volatility(
    const std::vector<double>& returns,
    int lookback
) const {
    std::vector<double> result(
        returns.size(),
        0.0
    );

    for (size_t i = lookback; i < returns.size(); ++i) {

        double mean = 0.0;

        for (size_t j = i - lookback; j < i; ++j)
            mean += returns[j];

        mean /= lookback;

        double var = 0.0;

        for (size_t j = i - lookback; j < i; ++j) {
            double d = returns[j] - mean;
            var += d * d;
        }

        var /= lookback;

        result[i] = std::sqrt(var);
    }

    return result;
}