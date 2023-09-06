// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// TLE at last test case, not sure why ?
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0 || len == 1) {
        return 0;
    }

    vector<int> dp(len, 0);
    int maxProfit = 0;
    for (int i = 1; i < len; i++) {
        dp[i] = dp[i - 1];
        for (int j = i - 1; j >= 0; j--) {
            if (prices[i] >= prices[j]){
                dp[i] = max(dp[i], (prices[i] - prices[j]) + (j == 0 ? 0 : dp[j - 1]));
            }
        }
        maxProfit = max(maxProfit, dp[i]);
    }

    return maxProfit;
}

// Optimised Solution
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0 || len == 1) {
        return 0;
    }
    int maxProfit = 0;
    for (int i = 1; i < len; i++) {
        maxProfit += max(0, prices[i] - prices[i - 1]);
    }

    return maxProfit;
}
