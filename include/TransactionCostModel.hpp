#pragma once

class TransactionCostModel {
public:

    double commission(
        double notional
    ) const;

    double slippage(
        double notional,
        double bps
    ) const;
};