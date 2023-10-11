// https://leetcode.com/problems/longest-increasing-subsequence/description/

int lengthOfLIS(vector<int>& nums) {
    int len = nums.size();

    vector<int> dp(len , 1);

    for (int i = 1; i < len; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLen = 1;

    for (int i = 0; i < len; i++) {
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}
