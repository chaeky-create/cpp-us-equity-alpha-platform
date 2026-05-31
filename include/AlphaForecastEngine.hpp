#pragma once

class AlphaForecastEngine
{
public:

    double expected_return(
        double alpha_score,
        double decay
    ) const;
};