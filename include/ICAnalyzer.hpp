#pragma once

#include <vector>

class ICAnalyzer {
public:
    double spearman_rank_ic(
        const std::vector<double>& factor,
        const std::vector<double>& future_returns
    ) const;
};