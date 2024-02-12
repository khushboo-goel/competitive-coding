// https://leetcode.com/problems/integer-break/description/
int integerBreak(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (n == 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }

    return dp[n];
}
