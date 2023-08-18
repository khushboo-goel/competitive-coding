class Solution {
public:
    int trap(vector<int>& height) {
        // first do O(n) approach
        int len = height.size();

        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int right = len - 1;
        int sum = 0;

        while(left <= right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                sum += leftMax - height[left];
                left ++;
            } else {
                rightMax = max(rightMax, height[right]);
                sum += rightMax - height[right];
                right --;
            }
        }

        return sum;
    }
};

// https://leetcode.com/problems/trapping-rain-water/description/
