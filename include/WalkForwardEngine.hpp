#pragma once

#include <vector>

struct WalkForwardSplit {
    int train_start;
    int train_end;
    int test_start;
    int test_end;
};

class WalkForwardEngine {
public:
    std::vector<WalkForwardSplit>
    generate_splits(
        int total_observations,
        int train_window,
        int test_window
    ) const;
};