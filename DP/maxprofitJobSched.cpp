// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
// NOTE: the dp is written in a particular order, keeping max for that particular instance and finding max value at end doesnt help to make it nlogn

// Solution reference: https://leetcode.com/problems/maximum-profit-in-job-scheduling/solutions/2742450/weighted-job-scheduling-algo-dp-binary-search

bool sortList(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
    return a.second.first < b.second.first;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len = startTime.size();

        vector<pair<int, pair<int, int>>> list;
        for (int i = 0; i < len; i++) {
            list.push_back(make_pair(startTime[i], make_pair(endTime[i], profit[i])));
        }

        sort(list.begin(), list.end(), sortList);
        vector<int> dp(len, 0);
        for(int i = 0; i < len; i++) {
            dp[i] = list[i].second.second;
        }

        for (int i = 1; i < len; i++) {
            int start = 0;
            int end = i - 1;
            
            int index = -1;
            int cost = 0;
            while(start <= end) {
                int mid = (end + start) / 2;

                if (list[mid].second.first <= list[i].first) {
                    if (cost < dp[mid]) {
                        index = mid;
                        cost = list[mid].second.second;
                    }
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            if (index != -1) {
                dp[i] = max(dp[i - 1], dp[index] + list[i].second.second);
            } else {
                dp[i] = max(dp[i - 1], list[i].second.second);
            }
        }
        return dp[len - 1];
    }
};
