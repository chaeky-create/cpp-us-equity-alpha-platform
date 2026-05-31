#include "ICAnalyzer.hpp"

#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

static std::vector<double> rank_vector(const std::vector<double>& values) {
    std::vector<std::pair<double, int>> temp;

    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        temp.push_back({values[i], i});
    }

    std::sort(temp.begin(), temp.end());

    std::vector<double> ranks(values.size());

    for (int i = 0; i < static_cast<int>(temp.size()); ++i) {
        ranks[temp[i].second] = static_cast<double>(i);
    }

    return ranks;
}

double ICAnalyzer::spearman_rank_ic(
    const std::vector<double>& factor,
    const std::vector<double>& future_returns
) const {
    if (factor.size() != future_returns.size() || factor.empty()) {
        return 0.0;
    }

    auto x = rank_vector(factor);
    auto y = rank_vector(future_returns);

    const int n = static_cast<int>(x.size());

    double mean_x = 0.0;
    double mean_y = 0.0;

    for (int i = 0; i < n; ++i) {
        mean_x += x[i];
        mean_y += y[i];
    }

    mean_x /= n;
    mean_y /= n;

    double numerator = 0.0;
    double denom_x = 0.0;
    double denom_y = 0.0;

    for (int i = 0; i < n; ++i) {
        const double dx = x[i] - mean_x;
        const double dy = y[i] - mean_y;

        numerator += dx * dy;
        denom_x += dx * dx;
        denom_y += dy * dy;
    }

    if (denom_x == 0.0 || denom_y == 0.0) {
        return 0.0;
    }

    return numerator / std::sqrt(denom_x * denom_y);
}