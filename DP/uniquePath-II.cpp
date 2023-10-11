// https://leetcode.com/problems/unique-paths-ii/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    vector<vector<int>> dp(n, vector(m, 0));

    bool obsSeen = false;
    for (int i = 0; i < n; i ++) {
        if (obstacleGrid[i][0] == 1) {
            dp[i][0] = 0;
            obsSeen = true;
        } else {
            dp[i][0] = obsSeen ? 0: 1;
        }
    }

    obsSeen = false;

    for (int i = 0; i < m; i ++) {
        if (obstacleGrid[0][i] == 1) {
            dp[0][i] = 0;
            obsSeen = true;
        } else {
            dp[0][i] = obsSeen ? 0: 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if (obstacleGrid[i][j] != 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
}
