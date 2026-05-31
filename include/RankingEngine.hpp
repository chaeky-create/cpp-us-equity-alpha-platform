#pragma once

#include <string>
#include <vector>

struct RankedStock {
    std::string ticker;
    double factor_value;
};

class RankingEngine {
public:

    std::vector<RankedStock>
    rank_descending(
        const std::vector<RankedStock>& stocks
    ) const;
};