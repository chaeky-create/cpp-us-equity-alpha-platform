#include "GridSearchEngine.hpp"

#include <algorithm>

std::vector<GridSearchResult>
GridSearchEngine::run(
    const std::vector<int>& lookbacks,
    const std::vector<double>& simulated_sharpes
) const {
    std::vector<GridSearchResult> results;

    const std::size_t n = std::min(
        lookbacks.size(),
        simulated_sharpes.size()
    );

    for (std::size_t i = 0; i < n; ++i) {
        results.push_back({
            lookbacks[i],
            simulated_sharpes[i]
        });
    }

    std::sort(
        results.begin(),
        results.end(),
        [](const GridSearchResult& a, const GridSearchResult& b) {
            return a.sharpe_ratio > b.sharpe_ratio;
        }
    );

    return results;
}