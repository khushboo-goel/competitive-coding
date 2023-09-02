// https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/
int longestLine(vector<vector<int>>& mat) {
    vector<int> dx = vector<int>({ 0, -1, -1, -1 });
    vector<int> dy = vector<int>({ -1, 0, -1, 1 });
    int len = mat.size();
    int bre = mat[0].size();
    if (len == 1 & bre == 1) {
        return mat[0][0];
    }

    vector<vector<vector<int>>> dp(4, vector<vector<int>>(len, vector<int>(bre, 0)));

    for (int i = 0; i < bre; i++) {
        for (int k = 0; k < 4; k++) {
            dp[k][0][i] = mat[0][i];
        }
    }

    int maxLen = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < bre; j++) {
            if (mat[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    dp[k][i][j] = 1;
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < len && y >= 0 && y < bre && mat[x][y] == 1) {                    
                        dp[k][i][j] = max(dp[k][i][j], dp[k][x][y] + 1);
                    }
                    maxLen = max(maxLen, dp[k][i][j]);
                }
            }
        }
    }

    return maxLen;
}
