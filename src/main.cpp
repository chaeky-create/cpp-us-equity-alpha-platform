#include "DataLoader.hpp"
#include "FactorEngine.hpp"
#include "PerformanceMetrics.hpp"

#include <iostream>
#include <vector>

int main() {
    std::cout << "C++ US Equity Alpha Research Platform\n";
    std::cout << "Phase 1: Project foundation initialized successfully.\n\n";

    std::vector<double> sample_returns = {
        0.002, -0.001, 0.003, 0.004, -0.002,
        0.001, 0.005, -0.003, 0.002, 0.001
    };

    PerformanceMetrics metrics;

    std::cout << "Sample Mean Return: "
              << metrics.mean(sample_returns) << "\n";

    std::cout << "Sample Volatility: "
              << metrics.volatility(sample_returns) << "\n";

    std::cout << "Sample Sharpe Ratio: "
              << metrics.sharpe_ratio(sample_returns) << "\n";

    std::cout << "Sample Max Drawdown: "
              << metrics.max_drawdown(sample_returns) << "\n";

    return 0;
}