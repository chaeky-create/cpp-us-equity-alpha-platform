#pragma once

#include "RankingEngine.hpp"
#include "DataLoader.hpp"

#include <string>
#include <unordered_map>
#include <vector>

struct Position {
    std::string ticker;
    double weight;
};

class PortfolioEngine {
public:
    std::vector<Position>
    build_long_short_portfolio(
        const std::vector<RankedStock>& ranked_stocks,
        int n_long,
        int n_short
    ) const;

    double calculate_portfolio_return(
        const std::vector<Position>& portfolio,
        const std::unordered_map<std::string, std::vector<PriceBar>>& universe,
        std::size_t date_index
    ) const;
};