#include "PortfolioEngine.hpp"

std::vector<Position>
PortfolioEngine::build_long_short_portfolio(
    const std::vector<RankedStock>& ranked_stocks,
    int n_long,
    int n_short
) const {
    std::vector<Position> portfolio;

    if (ranked_stocks.empty() || n_long <= 0 || n_short <= 0) {
        return portfolio;
    }

    const int total = static_cast<int>(ranked_stocks.size());

    if (n_long + n_short > total) {
        return portfolio;
    }

    const double long_weight = 1.0 / static_cast<double>(n_long);
    const double short_weight = -1.0 / static_cast<double>(n_short);

    for (int i = 0; i < n_long; ++i) {
        portfolio.push_back({ranked_stocks[i].ticker, long_weight});
    }

    for (int i = total - n_short; i < total; ++i) {
        portfolio.push_back({ranked_stocks[i].ticker, short_weight});
    }

    return portfolio;
}

double PortfolioEngine::calculate_portfolio_return(
    const std::vector<Position>& portfolio,
    const std::unordered_map<std::string, std::vector<PriceBar>>& universe,
    std::size_t date_index
) const {
    double portfolio_return = 0.0;

    for (const auto& position : portfolio) {
        const auto it = universe.find(position.ticker);

        if (it == universe.end()) {
            continue;
        }

        const auto& bars = it->second;

        if (date_index >= bars.size()) {
            continue;
        }

        portfolio_return += position.weight * bars[date_index].daily_return;
    }

    return portfolio_return;
}