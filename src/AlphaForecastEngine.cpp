#include "AlphaForecastEngine.hpp"

double
AlphaForecastEngine::expected_return(
    double alpha_score,
    double decay
) const
{
    return alpha_score * decay;
}