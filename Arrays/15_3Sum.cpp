// https://leetcode.com/problems/3sum/description/

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < n && nums[i] <= 0; i++) {
        if (i == 0 || nums[i - 1] != nums[i]) {
            int l = i + 1;
            int r = n - 1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> tuple = { nums[i], nums[l], nums[r]};
                    result.push_back(tuple);
                    l++; r--;
                    while(l < r && nums[r + 1] == nums[r]) {
                        r--;
                    }
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }

    return result;
}
