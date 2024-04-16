// https://leetcode.com/problems/find-all-duplicates-in-an-array/
vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i < n; i++) {
        int curr = abs(nums[i]);
        if (nums[curr - 1] < 0) {
            result.push_back(curr);
        } else {
            nums[curr - 1] = (-1) * nums[curr - 1];
        }
    }
    return result;
}
