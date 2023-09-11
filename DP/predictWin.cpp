// https://leetcode.com/problems/predict-the-winner/
// NOTE: Thinking this as the max points gained by player one in each round will help understand this solution.

bool predictTheWinner(vector<int>& nums) {
    int len = nums.size();

    if (len == 0 || len == 1) {
        return true;
    }

    vector<vector<int>> dp(len, vector<int>(len, 0));
    for(int i = 0; i < len; i++) {
        dp[i][i] = nums[i];
    }

    for (int n = 2; n <= len; n++) {
        for (int i = 0; i < len - n + 1; i++) {
            int j = i + n - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][len - 1] >= 0;
}
