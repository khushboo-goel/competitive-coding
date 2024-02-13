int minTaps(int n, vector<int>& ranges) {
    vector<int> dp(n + 1, INT_MAX - 1);

    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        int start = i - ranges[i] < 0 ? 0 : i - ranges[i];
        int end = i + ranges[i] > n ? n : i + ranges[i];

        for (int j = start; j <= end; j++) {
            dp[end] = min(dp[end], dp[j] + 1);
        }
    }

    return dp[n] == INT_MAX - 1 ? - 1 : dp[n];
}
