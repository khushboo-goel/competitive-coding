// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

vector<int> searchRange(vector<int>& nums, int target) {
    int firstPos = -1;
    int lastPos = -1;

    int left = 0;
    int right = nums.size() - 1;

    while(left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (mid == 0 || nums[mid - 1] != target) {
                firstPos = mid;
                break;
            } else {
                right = mid - 1;
            }
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }


    left = 0;
    right = nums.size() - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                lastPos = mid;
                break;
            } else {
                left = mid + 1;
            }
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    vector<int> res;
    res.push_back(firstPos);
    res.push_back(lastPos);

    return res;
}
