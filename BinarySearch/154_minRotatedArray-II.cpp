// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=list&envId=pcxjbubg

int findMin(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) {
        return nums[0];
    }

    int left = 0;
    int right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if (mid == 0) {
            if (nums[mid] <= nums[mid + 1]) {
                return nums[mid];
            } else {
                left = mid + 1;
            }
        } else if (nums[mid] < nums[mid - 1]) {
            return nums[mid];
        } else if (nums[mid] <= nums[right]) {
            if (nums[mid] == nums[right]) {
                right --;
            } else {
                right = mid - 1;
            }
        } else {
            left = mid + 1;
        }
    }

    return -1;
}
