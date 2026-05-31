#include "MultiFactorAlphaModel.hpp"

double
MultiFactorAlphaModel::alpha(
    double momentum,
    double value,
    double quality,
    double low_vol
) const
{
    return
        0.40 * momentum
        +
        0.30 * value
        +
        0.20 * quality
        +
        0.10 * low_vol;
}