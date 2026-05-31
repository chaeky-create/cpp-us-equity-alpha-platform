#pragma once

#include <vector>

class FactorLibrary {
public:

    std::vector<double>
    momentum(
        const std::vector<double>& prices,
        int lookback
    ) const;

    std::vector<double>
    mean_reversion(
        const std::vector<double>& prices,
        int lookback
    ) const;

    std::vector<double>
    volatility(
        const std::vector<double>& returns,
        int lookback
    ) const;
};