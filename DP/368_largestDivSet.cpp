vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || n == 1) {
        return nums;
    }

    sort(nums.begin(), nums.end());
    vector<vector<int>> elements;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] % nums[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}
