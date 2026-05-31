#include "AlphaDecayModel.hpp"

#include <cmath>

double
AlphaDecayModel::half_life(
    double decay_rate
) const
{
    return
        std::log(0.5)
        /
        std::log(decay_rate);
}