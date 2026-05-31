#pragma once

#include "DataLoader.hpp"

#include <vector>

class FactorEngine {
public:
    std::vector<double> momentum(const std::vector<PriceBar>& data, int lookback_days) const;
    std::vector<double> reversal(const std::vector<PriceBar>& data, int lookback_days) const;
};