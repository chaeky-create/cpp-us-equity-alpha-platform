#include "DataLoader.hpp"
#include "FactorEngine.hpp"
#include "ICAnalyzer.hpp"
#include "UniverseLoader.hpp"
#include "RankingEngine.hpp"
#include "PortfolioEngine.hpp"
#include "Backtester.hpp"

#include <iostream>
#include <cmath>

int main() {
    DataLoader loader;
    FactorEngine factor_engine;

    auto data = loader.load_csv("../data/raw/AAPL.csv");

    auto momentum_252 = factor_engine.momentum(data, 252);

    std::cout << "Rows loaded: " << data.size() << "\n";
    std::cout << "First date: " << data.front().date << "\n";
    std::cout << "Last date: " << data.back().date << "\n\n";

    std::cout << "252-day Momentum Factor Sample\n";

    for (std::size_t i = data.size() - 5; i < data.size(); ++i) {
        std::cout
            << data[i].date
            << " | Close: " << data[i].close
            << " | Momentum252: " << momentum_252[i]
            << "\n";
    }

    std::vector<double> factor = {
    1,2,3,4,5,6
    };

    std::vector<double> future_returns = {
        0.01,
        0.02,
        0.03,
        0.04,
        0.05,
        0.06
    };

    ICAnalyzer ic;

    std::cout
        << "\nIC = "
        << ic.spearman_rank_ic(
            factor,
            future_returns
        )
        << "\n";

    
    UniverseLoader universe_loader;

    std::vector<std::string> tickers = {
        "AAPL",
        "MSFT",
        "NVDA",
        "META",
        "AMZN",
        "GOOGL"
    };

    auto universe =
        universe_loader.load_universe(
            tickers
        );

    std::cout
    << "\nUniverse Size: "
    << universe.size()
    << "\n";

    for(const auto& [ticker, bars] : universe) {

        std::cout
        << ticker
        << " -> "
        << bars.size()
        << " rows\n";
    }


   std::vector<RankedStock> stocks = {
    {"AAPL", 0.31},
    {"MSFT", 0.18},
    {"NVDA", 0.52},
    {"META", 0.27},
    {"AMZN", 0.11},
    {"GOOGL", 0.22}
    };

    RankingEngine ranking_engine;

    auto ranked =
        ranking_engine.rank_descending(
            stocks
        );

    std::cout
    << "\nMomentum Ranking\n";

    for(const auto& stock : ranked) {

        std::cout
        << stock.ticker
        << " "
        << stock.factor_value
        << "\n";
    }


    PortfolioEngine portfolio_engine;

    auto portfolio =
        portfolio_engine.build_long_short_portfolio(
            ranked,
            2,
            2
        );

    std::cout << "\nLong/Short Portfolio\n";

    for (const auto& position : portfolio) {
        std::cout
            << position.ticker
            << " weight: "
            << position.weight
            << "\n";
    }


    std::size_t test_index = universe["AAPL"].size() - 1;

    double portfolio_return =
        portfolio_engine.calculate_portfolio_return(
            portfolio,
            universe,
            test_index
        );

    std::cout
        << "\nPortfolio Return on "
        << universe["AAPL"][test_index].date
        << ": "
        << portfolio_return
        << "\n";


    std::vector<double> test_returns;

    test_returns.push_back(0.01);
    test_returns.push_back(-0.005);
    test_returns.push_back(0.02);
    test_returns.push_back(0.015);
    test_returns.push_back(-0.01);

    Backtester bt;

    auto result =
        bt.run(test_returns);

    std::cout
        << "\nCumulative Return = "
        << result.cumulative_return
        << "\n";

    return 0;
}