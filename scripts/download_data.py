import yfinance as yf
from pathlib import Path

tickers = [
    "AAPL",
    "MSFT",
    "NVDA",
    "AMZN",
    "META",
    "GOOGL"
]

output_dir = Path("data/raw")
output_dir.mkdir(parents=True, exist_ok=True)

for ticker in tickers:
    print(f"Downloading {ticker}")

    df = yf.download(
        ticker,
        start="2015-01-01",
        end="2025-01-01",
        auto_adjust=True
    )

    df.to_csv(output_dir / f"{ticker}.csv")

print("Done.")