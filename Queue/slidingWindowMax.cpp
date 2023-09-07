class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> result;

        // O(n ^ 2) brute force approach

        // int maxVal = INT_MIN;
        // for (int i = 0; i < k; i ++) {
        //     maxVal = nums[i] > maxVal ? nums[i] : maxVal;
        // }
        // result.push_back(maxVal);

        // for(int i = 1; i <= len - k; i++) {
        //     if (nums[i + k - 1] > maxVal){
        //         maxVal = nums[i + k - 1];
        //         result.push_back(maxVal);
        //     } else if (nums[i - 1] == maxVal) {
        //         maxVal = INT_MIN;
        //         for (int j = i; j < i + k; j++) {
        //             maxVal = nums[j] > maxVal ? nums[j] : maxVal;
        //         }
        //         result.push_back(maxVal);
        //     } else {
        //         result.push_back(maxVal);
        //     }
        // }

        // time O(n) and space O(n)

        deque<int> maxVal;
        for (int i = 0; i < k; i++) {
            while (maxVal.size() > 0 && nums[i] > nums[maxVal.back()]) {
                maxVal.pop_back();
            }
            maxVal.push_back(i);
        }

        int j = k;
        for(int i = 0; i < len - k + 1; i++){
            result.push_back(nums[maxVal.front()]);
            if (j < len) {
                while(maxVal.size() > 0 && i >= maxVal.front()) {
                    maxVal.pop_front();
                }

                while (maxVal.size() > 0 && nums[j] > nums[maxVal.back()]) {
                    maxVal.pop_back();
                }
                maxVal.push_back(j);
                j++;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/sliding-window-maximum/description/
