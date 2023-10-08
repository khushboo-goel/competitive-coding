// https://leetcode.com/problems/minimize-maximum-of-array/description/
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int len = nums.size();

        long long minVal = 0;
        long long sum = 0;

        for (int i = 0; i < len; i++) {
            sum += nums[i];
            minVal = max(minVal, (long long)((sum + i) / (i + 1)));
        }

        return minVal;
    }
};
