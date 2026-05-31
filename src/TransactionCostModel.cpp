#include "TransactionCostModel.hpp"

double TransactionCostModel::commission(
    double notional
) const
{
    return notional * 0.0005;
}

double TransactionCostModel::slippage(
    double notional,
    double bps
) const
{
    return notional * (bps / 10000.0);
}