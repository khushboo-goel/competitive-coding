// https://leetcode.com/problems/next-permutation/description/
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    for (; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }

    if (i < 0) {
        reverse(nums.begin(), nums.end());
        return;
    } else {
        int j = n - 1;
        while(nums[j] <= nums[i]) {
            j--;
        }
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        sort(nums.begin() + i + 1, nums.end());
    }
}
