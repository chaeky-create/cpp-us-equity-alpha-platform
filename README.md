# C++ US Equity Alpha Research Platform

A C++ quantitative research platform for US equity alpha generation, factor validation, portfolio construction, backtesting, walk-forward validation, and parameter optimization.

## Features

- Yahoo Finance data ingestion
- Daily OHLCV data loading
- 252-day momentum factor generation
- Spearman rank IC analysis
- Multi-asset universe loading
- Cross-sectional stock ranking
- Dollar-neutral long/short portfolio construction
- Portfolio return calculation
- Backtest performance metrics
  - Cumulative return
  - Annual return
  - Annual volatility
  - Sharpe ratio
  - Maximum drawdown
- Walk-forward validation
- Parameter grid search

## Project Structure

```text
include/
src/
scripts/
data/raw/
results/
docs/


Universe Size: 6

Momentum Ranking
NVDA 0.52
AAPL 0.31
META 0.27
GOOGL 0.22
MSFT 0.18
AMZN 0.11

Long/Short Portfolio
NVDA weight: 0.5
AAPL weight: 0.5
MSFT weight: -0.5
AMZN weight: -0.5

Sharpe Ratio = 7.35943
Max Drawdown = -0.01


Technology Stack
- C++ 20
CMake
Python
Yahoo Finance
Git
GitHub