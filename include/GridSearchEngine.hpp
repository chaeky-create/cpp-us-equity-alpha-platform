#pragma once

#include <vector>

struct GridSearchResult {
    int lookback_days;
    double sharpe_ratio;
};

class GridSearchEngine {
public:
    std::vector<GridSearchResult>
    run(
        const std::vector<int>& lookbacks,
        const std::vector<double>& simulated_sharpes
    ) const;
};