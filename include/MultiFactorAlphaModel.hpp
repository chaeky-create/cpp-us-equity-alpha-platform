#pragma once

class MultiFactorAlphaModel
{
public:

    double alpha(
        double momentum,
        double value,
        double quality,
        double low_vol
    ) const;
};