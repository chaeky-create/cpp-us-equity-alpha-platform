#include "RankingEngine.hpp"

#include <algorithm>

std::vector<RankedStock>
RankingEngine::rank_descending(
    const std::vector<RankedStock>& stocks
) const {

    auto ranked = stocks;

    std::sort(
        ranked.begin(),
        ranked.end(),
        [](const RankedStock& a,
           const RankedStock& b)
        {
            return a.factor_value >
                   b.factor_value;
        }
    );

    return ranked;
}