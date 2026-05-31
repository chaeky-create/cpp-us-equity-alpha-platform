#pragma once

#include "DataLoader.hpp"

#include <string>
#include <unordered_map>
#include <vector>

class UniverseLoader {
public:

    std::unordered_map<
        std::string,
        std::vector<PriceBar>
    >
    load_universe(
        const std::vector<std::string>& tickers
    ) const;
};