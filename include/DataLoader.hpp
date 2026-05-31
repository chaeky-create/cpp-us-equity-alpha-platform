#pragma once

#include <string>
#include <vector>

struct PriceBar {
    std::string date;

    double close{};
    double high{};
    double low{};
    double open{};
    double volume{};

    double daily_return{};
};

class DataLoader {
public:
    std::vector<PriceBar> load_csv(const std::string& filepath) const;
};