#include "DataLoader.hpp"
#include "FactorEngine.hpp"
#include "ICAnalyzer.hpp"
#include "UniverseLoader.hpp"
#include "RankingEngine.hpp"
#include "PortfolioEngine.hpp"
#include "Backtester.hpp"
#include "WalkForwardEngine.hpp"
#include "GridSearchEngine.hpp"
#include "FactorLibrary.hpp"
#include "CorrelationEngine.hpp"
#include "RiskModel.hpp"
#include "TransactionCostModel.hpp"
#include "PositionSizingEngine.hpp"
#include "PortfolioOptimizer.hpp"
#include "MeanVarianceOptimizer.hpp"
#include "PortfolioRebalancer.hpp"
#include "MultiFactorAlphaModel.hpp"
#include "FactorNeutralizer.hpp"
#include "AlphaForecastEngine.hpp"
#include "AlphaDecayModel.hpp"
#include "SignalCombiner.hpp"

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

    std::cout << "Annual Return = " << result.annual_return << "\n";
    std::cout << "Annual Volatility = " << result.annual_volatility << "\n";
    std::cout << "Sharpe Ratio = " << result.sharpe_ratio << "\n";
    std::cout << "Max Drawdown = " << result.max_drawdown << "\n";


    WalkForwardEngine wf;

    auto splits = wf.generate_splits(
        2516,
        756,
        252
    );

    std::cout << "\nWalk-Forward Splits\n";

    for (const auto& split : splits) {
        std::cout
            << "Train: " << split.train_start << "-" << split.train_end
            << " | Test: " << split.test_start << "-" << split.test_end
            << "\n";
    }


    GridSearchEngine grid;

    std::vector<int> lookbacks = {21, 63, 126, 252, 504};
    std::vector<double> simulated_sharpes = {0.82, 1.14, 1.47, 1.91, 1.32};

    auto grid_results = grid.run(
        lookbacks,
        simulated_sharpes
    );

    std::cout << "\nGrid Search Results\n";

    for (const auto& r : grid_results) {
        std::cout
            << "Lookback: "
            << r.lookback_days
            << " | Sharpe: "
            << r.sharpe_ratio
            << "\n";
    }


    FactorLibrary factors;

    std::vector<double> prices = {
        100,
        102,
        101,
        105,
        107,
        110,
        108,
        112
    };

    auto momentum =
        factors.momentum(prices, 3);

    auto mean_reversion =
        factors.mean_reversion(prices, 3);

    std::vector<double> returns = {
        0.01,
        -0.02,
        0.03,
        -0.01,
        0.02,
        0.01,
        -0.01,
        0.02
    };

    auto volatility =
        factors.volatility(
            returns,
            3
        );

    std::cout
        << "\nFactor Library Sample\n";

    std::cout
        << "Momentum Last: "
        << momentum.back()
        << "\n";

    std::cout
        << "Mean Reversion Last: "
        << mean_reversion.back()
        << "\n";

    std::cout
        << "Volatility Last: "
        << volatility.back()
        << "\n";


    CorrelationEngine corr;

    std::vector<double> stock_a =
    {
        0.01,
        0.02,
        -0.01,
        0.03,
        0.01
    };

    std::vector<double> stock_b =
    {
        0.02,
        0.01,
        -0.02,
        0.04,
        0.02
    };

    std::cout
        << "\nCorrelation Sample\n"
        << corr.correlation(
            stock_a,
            stock_b
        )
        << "\n";


    RiskModel risk;

    std::cout
        << "\nRisk Model Sample\n"
        << "Covariance = "
        << risk.covariance(
            stock_a,
            stock_b
        )
        << "\n";


    TransactionCostModel cost_model;

    double trade_notional = 100000.0;

    std::cout
        << "\nTransaction Cost Sample\n";

    std::cout
        << "Commission = "
        << cost_model.commission(
            trade_notional
        )
        << "\n";

    std::cout
        << "Slippage = "
        << cost_model.slippage(
            trade_notional,
            5.0
        )
        << "\n";


    PositionSizingEngine sizing;

    std::cout
        << "\nPosition Sizing Sample\n";

    std::cout
        << "Vol Target Weight = "
        << sizing.volatilityTargetWeight(
            0.15,
            0.25
        )
        << "\n";

    std::cout
        << "Kelly Fraction = "
        << sizing.kellyFraction(
            0.55,
            2.0
        )
        << "\n";


    PortfolioOptimizer optimizer;

    auto equal =
        optimizer.equalWeight(4);

    auto invVol =
        optimizer.inverseVolWeight(
            {
                0.20,
                0.30,
                0.25,
                0.40
            }
        );

    std::cout
        << "\nPortfolio Optimizer\n";

    std::cout
        << "Equal Weights\n";

    for(double w : equal)
    {
        std::cout << w << "\n";
    }

    std::cout
        << "\nInverse Vol Weights\n";

    for(double w : invVol)
    {
        std::cout << w << "\n";
    }


    MeanVarianceOptimizer mvo;

    auto weights =
        mvo.optimize(
            {
                0.15,
                0.12,
                0.08,
                0.05
            },
            {
                0.04,
                0.09,
                0.06,
                0.03
            }
        );

    std::cout
        << "\nMean Variance Optimizer\n";

    for(double w : weights)
    {
        std::cout
            << w
            << "\n";
    }


    PortfolioRebalancer rebalancer;

    double turnover =
        rebalancer.turnover(
            {
                0.25,
                0.25,
                0.25,
                0.25
            },
            {
                0.40,
                0.30,
                0.20,
                0.10
            }
        );

        std::cout
            << "\nPortfolio Rebalancer\n";

        std::cout
            << "Turnover = "
            << turnover
            << "\n";

    MultiFactorAlphaModel alpha_model;

    double alpha_score =
        alpha_model.alpha(
            0.80,
            0.60,
            0.70,
            0.50
        );

    std::cout
        << "\nMulti Factor Alpha Model\n";

    std::cout
        << "Alpha Score = "
        << alpha_score
        << "\n";

    FactorNeutralizer neutralizer;

    std::vector<double> sector_exposure =
    {
        1.2,
        0.9,
        1.4,
        0.8
    };

    auto neutralized =
        neutralizer.demean(
            sector_exposure
        );

    std::cout
        << "\nFactor Neutralizer\n";

    for(double x : neutralized)
    {
        std::cout
            << x
            << "\n";
    }


    AlphaForecastEngine forecast;

    double forecast_return =
        forecast.expected_return(
            0.69,
            0.85
        );

    std::cout
        << "\nAlpha Forecast Engine\n";

    std::cout
        << "Expected Return = "
        << forecast_return
        << "\n";


    AlphaDecayModel decay_model;

    double hl =
        decay_model.half_life(
            0.85
        );

    std::cout
        << "\nAlpha Decay Model\n";

    std::cout
        << "Half Life = "
        << hl
        << "\n";



    SignalCombiner combiner;

    std::vector<double> momentum_signal = {
        0.8,
        0.6,
        0.2,
        -0.1
    };

    std::vector<double> value_signal = {
        0.4,
        0.7,
        0.3,
        0.1
    };

    auto z_momentum =
        combiner.zscore(
            momentum_signal
        );

    auto z_value =
        combiner.zscore(
            value_signal
        );

    auto combined_signal =
        combiner.combine(
            z_momentum,
            z_value,
            0.6,
            0.4
        );

    std::cout
        << "\nSignal Combiner\n";

    for (double x : combined_signal)
    {
        std::cout
            << x
            << "\n";
    }

    return 0;
}