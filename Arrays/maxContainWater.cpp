// https://leetcode.com/problems/container-with-most-water/

int maxArea(vector<int>& height) {
    int len = height.size();
    if (len == 0 || len == 1) {
        return 0;
    }

    int left = 0;
    int right = len - 1;
    int maxWater = 0;
    
    while(left <= right) {
        int area = min(height[left], height[right]) * (right - left);
        maxWater = max(maxWater, area);
        if (height[left] < height[right]) {
            left++;
        } else {
            right --;
        }
    }

    return maxWater;
}
