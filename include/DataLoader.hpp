#pragma once

#include <string>
#include <vector>

struct PriceBar {
    std::string date;
    std::string ticker;
    double open{};
    double high{};
    double low{};
    double close{};
    double adjusted_close{};
    long long volume{};
    double daily_return{};
};

class DataLoader {
public:
    std::vector<PriceBar> load_csv(const std::string& filepath, const std::string& ticker) const;
};