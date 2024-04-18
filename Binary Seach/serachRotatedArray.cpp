class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            if (nums[mid] == target) {
                return mid;
            } else {
                int posn = (nums[mid] < nums[left]) ? 0 : 1;

                if (posn == 0) {
                    if (nums[mid] < target && nums[right] >= target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (nums[mid] > target && nums[left] <= target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }

        return -1;
    }
};

// https://leetcode.com/problems/search-in-rotated-sorted-array/
