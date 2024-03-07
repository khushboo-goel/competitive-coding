// https://leetcode.com/problems/jump-game/
bool canJump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return true;
    }

    vector<bool> dp(n, false);
    dp[0] = true;

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] + j >= i && dp[j] == true) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n - 1];
}
