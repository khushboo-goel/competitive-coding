// https://leetcode.com/problems/first-missing-positive/
// NOTE: Hard is only the approach. This approach kind of uses same array with concept of bucket sort, using signs instead of numbers

int firstMissingPositive(vector<int>& nums) {
    int count = 0;
    int len = nums.size();

    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] <= 0 || nums[i] > len) {
            nums[i] = len + 1;
        }
    }

    for (int i = 0; i < len; i++) {
        int val = abs(nums[i]);
        if (val <= len && nums[val - 1] > 0) {
            nums[val - 1] = (-1) * (nums[val - 1]);
        }
    }

    for (int i = 0; i < len; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    return len + 1;
}
