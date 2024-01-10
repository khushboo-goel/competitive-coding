// https://leetcode.com/problems/paint-house/description/
int minCost(vector<vector<int>>& costs) {
  int len = cost.size();
  
  // three for three different colors
  vector<vector<int>> dp(len, vector<int>(3, 0));
  dp[0][0] = costs[0][0];
  dp[0][1] = costs[0][1];
  dp[0][2] = costs[0][2];
  
  for (int i = 1; i < len; i++) {
      dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
  }
  
  return min(dp[len - 1][0], min(dp[len - 1][1], dp[len - 1][2]));
}
