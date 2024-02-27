// https://leetcode.com/problems/perfect-squares/

int numSquares(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    vector<int> sq;
    for (int i = 1; i <= n; i++) {
        sq.push_back(i * i);
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int j = 0;
        while(sq[j] <= i) {
            if (sq[j] == i) {
                dp[i] = 1;
            } else {
                dp[i] = min(dp[i], dp[sq[j]] + dp[i - sq[j]]);
            }
            j++;
        }
    }

    return dp[n];
}
