// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int len = weights.size();

        int leastWeightInNDays = INT_MIN;
        int leastWeightInOneDay = 0;
        for (int i = 0; i < len; i++) {
            leastWeightInNDays = max(leastWeightInNDays, weights[i]);
            leastWeightInOneDay += weights[i];
        }

        int start = leastWeightInNDays;
        int end = leastWeightInOneDay;

        int leastWeight = leastWeightInOneDay;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            int daysNeeded = 0;
            int currWeight = 0;
            for (int i = 0; i < len; i++) {
                if (currWeight + weights[i] <= mid) {
                    currWeight += weights[i];
                } else {
                    daysNeeded ++;
                    currWeight = weights[i];
                }

                if (i == len - 1) {
                    daysNeeded ++;
                }
            }

            if (daysNeeded > days) {
                start = mid + 1;
            } else {
                if (mid < leastWeight) {
                    leastWeight = mid;
                }
                end = mid - 1;
            }
        }

        return leastWeight;
    }
};
