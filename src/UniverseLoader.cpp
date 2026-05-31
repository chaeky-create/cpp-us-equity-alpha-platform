#include "UniverseLoader.hpp"

std::unordered_map<
    std::string,
    std::vector<PriceBar>
>
UniverseLoader::load_universe(
    const std::vector<std::string>& tickers
) const {

    DataLoader loader;

    std::unordered_map<
        std::string,
        std::vector<PriceBar>
    > universe;

    for(const auto& ticker : tickers) {

        std::string path =
            "../data/raw/" +
            ticker +
            ".csv";

        universe[ticker] =
            loader.load_csv(path);
    }

    return universe;
}