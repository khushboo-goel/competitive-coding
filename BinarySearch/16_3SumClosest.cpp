// https://leetcode.com/problems/3sum-closest/description/
int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int total = 0;

    for(int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int sum = nums[left] + nums[right] + nums[i];
            if (abs(target - sum) < diff) {
                total = sum;
                diff = abs(target - sum);
            }
            if (target - sum == 0) {
                return sum;
            } else if (target - sum < 0) {
                right --;
            } else if (target - sum > 0) {
                left ++;
            }
        }
    }

    return total;
}
