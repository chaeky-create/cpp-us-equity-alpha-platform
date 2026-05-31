#include "PositionSizingEngine.hpp"

double PositionSizingEngine::volatilityTargetWeight(
    double target_vol,
    double asset_vol
) const
{
    return target_vol / asset_vol;
}

double PositionSizingEngine::kellyFraction(
    double win_rate,
    double payoff_ratio
) const
{
    return win_rate
         - ((1.0 - win_rate)
         / payoff_ratio);
}