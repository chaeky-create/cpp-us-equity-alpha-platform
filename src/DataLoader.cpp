#include "DataLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<PriceBar> DataLoader::load_csv(const std::string& filepath) const {

    std::ifstream file(filepath);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file");
    }

    std::string line;

    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);

    std::vector<PriceBar> data;

    double previous_close = 0.0;

    while (std::getline(file, line)) {

        std::stringstream ss(line);

        std::string date;
        std::string close;
        std::string high;
        std::string low;
        std::string open;
        std::string volume;

        std::getline(ss, date, ',');
        std::getline(ss, close, ',');
        std::getline(ss, high, ',');
        std::getline(ss, low, ',');
        std::getline(ss, open, ',');
        std::getline(ss, volume, ',');

        PriceBar bar;

        bar.date = date;
        bar.close = std::stod(close);
        bar.high = std::stod(high);
        bar.low = std::stod(low);
        bar.open = std::stod(open);
        bar.volume = std::stod(volume);

        if (previous_close > 0.0) {
            bar.daily_return =
                (bar.close / previous_close) - 1.0;
        }

        previous_close = bar.close;

        data.push_back(bar);
    }

    return data;
}