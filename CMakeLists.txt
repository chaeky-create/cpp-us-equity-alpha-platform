cmake_minimum_required(VERSION 3.20)

project(cpp_us_equity_alpha_platform VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(alpha_platform
    src/main.cpp
    src/DataLoader.cpp
    src/FactorEngine.cpp
    src/ICAnalyzer.cpp
    src/PortfolioEngine.cpp
    src/Backtester.cpp
    src/PerformanceMetrics.cpp
    src/UniverseLoader.cpp
    src/RankingEngine.cpp
    src/WalkForwardEngine.cpp
    src/GridSearchEngine.cpp
    src/FactorLibrary.cpp
    src/CorrelationEngine.cpp
    src/RiskModel.cpp
    src/TransactionCostModel.cpp
    src/PositionSizingEngine.cpp
    src/PortfolioOptimizer.cpp
    src/MeanVarianceOptimizer.cpp
    src/PortfolioRebalancer.cpp
    src/MultiFactorAlphaModel.cpp
    src/FactorNeutralizer.cpp
    src/AlphaForecastEngine.cpp
    src/AlphaDecayModel.cpp
    src/SignalCombiner.cpp
)

target_include_directories(alpha_platform PRIVATE include)