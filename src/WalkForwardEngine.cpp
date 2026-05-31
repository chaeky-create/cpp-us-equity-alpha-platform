#include "WalkForwardEngine.hpp"

std::vector<WalkForwardSplit>
WalkForwardEngine::generate_splits(
    int total_observations,
    int train_window,
    int test_window
) const {
    std::vector<WalkForwardSplit> splits;

    int start = 0;

    while (start + train_window + test_window <= total_observations) {
        WalkForwardSplit split;

        split.train_start = start;
        split.train_end = start + train_window - 1;
        split.test_start = start + train_window;
        split.test_end = start + train_window + test_window - 1;

        splits.push_back(split);

        start += test_window;
    }

    return splits;
}