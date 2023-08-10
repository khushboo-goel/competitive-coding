class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int modifiedK = (k % len);
        queue<int> tmps;
        for(int i = len - modifiedK; i < len ; i++){
            tmps.push(nums[i]);
        }
        for(int i = 0; i < len - modifiedK; i++){
            tmps.push(nums[i]);
        }

        int count = 0;
        while(!tmps.empty()) { 
            nums[count] = tmps.front();
            tmps.pop();
            count ++;
        }
    }
};

// mind boggling solution: https://leetcode.com/problems/rotate-array/solutions/3506340/beats-100-3-line-solution-fully-most-optimised-code/
// https://leetcode.com/problems/rotate-array/description/
