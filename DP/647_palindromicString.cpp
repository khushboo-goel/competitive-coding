// https://leetcode.com/problems/palindromic-substrings/description/
int countSubstrings(string s) {
    int n = s.length();
    if (n == 0 || n == 1) {
        return 1;
    }

    int count = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        count++;
    }

    for (int l = 2; l <= n; l++) {
        for(int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && ( i + 1 > j - 1 || dp[i + 1][j - 1] == true)) {
                dp[i][j] = true;
                count++;
            }
        }
    }

    return count;
}
