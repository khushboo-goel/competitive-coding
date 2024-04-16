// https://leetcode.com/problems/subarray-product-less-than-k/
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();

    if (k == 0 || k == 1) {
        return 0;
    }
    int product = 1;
    int count = 0;
    int i = 0;
    for (int j = 0; j < n; j++) {
        product = product * nums[j];

        while(product >= k) {
            product = product / nums[i];
            i++;
        }
        count += (j - i + 1);
    }

    return count;
}
