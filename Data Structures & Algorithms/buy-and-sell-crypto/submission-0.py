class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        mxprice = [0 for _ in range(n+1)]
        for i in range(n-1,-1,-1):
            mxprice[i] = max(mxprice[i+1],prices[i])
        profit = 0
        for i in range(n):
            profit = max(profit, mxprice[i+1] - prices[i])
        return profit