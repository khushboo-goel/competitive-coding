// NOTE: This is substring (contigous) not subsequence.
// https://leetcode.com/problems/longest-palindromic-substring/description/

string longestPalindrome(string s) {
  int n = s.length();
  if (n == 0 || n == 1) {
      return s;
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
  }

  int start = 0, end = 0;
  for (int len = 2; len <= n; len++){
      for(int i = 0; i < n - len + 1; i++) {
          int j = i + len - 1;
          if (s[i] == s[j] && (j - 1 < i + 1 || dp[i + 1][j - 1])) {
              dp[i][j] = 1;
              start = i;
              end = j;
          }
      }
  }

  return s.substr(start, end - start + 1);
}
