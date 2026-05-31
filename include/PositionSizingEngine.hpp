#pragma once

class PositionSizingEngine {
public:

    double volatilityTargetWeight(
        double target_vol,
        double asset_vol
    ) const;

    double kellyFraction(
        double win_rate,
        double payoff_ratio
    ) const;
};