#include "DataLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<PriceBar> DataLoader::load_csv(const std::string& filepath, const std::string& ticker) const {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filepath);
    }

    std::vector<PriceBar> data;
    std::string line;

    std::getline(file, line); // header

    double previous_adjusted_close = 0.0;
    bool has_previous = false;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;

        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() < 6) {
            continue;
        }

        PriceBar bar;
        bar.date = fields[0];
        bar.ticker = ticker;
        bar.open = std::stod(fields[1]);
        bar.high = std::stod(fields[2]);
        bar.low = std::stod(fields[3]);
        bar.close = std::stod(fields[4]);
        bar.adjusted_close = std::stod(fields[5]);

        if (fields.size() >= 7) {
            bar.volume = std::stoll(fields[6]);
        }

        if (has_previous && previous_adjusted_close > 0.0) {
            bar.daily_return = (bar.adjusted_close / previous_adjusted_close) - 1.0;
        } else {
            bar.daily_return = 0.0;
        }

        previous_adjusted_close = bar.adjusted_close;
        has_previous = true;

        data.push_back(bar);
    }

    return data;
}