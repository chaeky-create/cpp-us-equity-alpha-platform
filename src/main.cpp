#include "DataLoader.hpp"
#include "FactorEngine.hpp"

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

    return 0;
}