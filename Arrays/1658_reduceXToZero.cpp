// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += nums[i];
    }

    if (x > total) {
        return -1;
    }
    total = total - x;

    if (total == 0) {
        return n;
    } 
    int i = 0, j = 0;
    int maxLen = INT_MIN;

    int currSum = 0;
    while(i < n && j < n) {
        currSum += nums[j];
        if (currSum == total) {
            maxLen = max(maxLen, j - i + 1);
            j++;
        } else if (currSum < total) {
            j++;
        } else {
            currSum -= nums[i];
            currSum -= nums[j];
            i++;
        }
    }

    return maxLen == INT_MIN ? -1 : n - maxLen;
}
