// https://leetcode.com/problems/find-triangular-sum-of-an-array/description/
int triangularSum(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }

    vector<int> tmp(nums.begin(), nums.end());

    while(tmp.size() > 1) {
        vector<int> newTemp;
        for (int i = 0; i < tmp.size() - 1; i ++) {
            newTemp.push_back((tmp[i] + tmp[i + 1]) % 10);
        }

        tmp = newTemp;
    }

    return tmp[0];
}
