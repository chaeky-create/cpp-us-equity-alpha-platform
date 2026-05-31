#pragma once

#include "BacktestResult.hpp"

#include <vector>

class Backtester {
public:
    BacktestResult run(
        const std::vector<double>& returns
    ) const;
};