// https://leetcode.com/problems/subarray-sum-equals-k/

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sums;
    sums[0] = 1;
    int sum = 0, count = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sums.find(sum - k) != sums.end()) {
            count += sums[sum - k];
        }
        sums[sum]++;
    }

    return count;
}
