// https://leetcode.com/problems/maximum-subarray/
int maxSubArray(vector<int>& nums) {
    int n = nums.size();

    int maxSum = INT_MIN;

    int currSum = 0;
    for(int i = 0; i < n; i++) {
        currSum += nums[i];
        if (currSum >= maxSum) {
            maxSum = currSum;
        }
        if (currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}
