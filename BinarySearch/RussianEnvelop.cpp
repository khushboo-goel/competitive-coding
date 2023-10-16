// https://leetcode.com/problems/russian-doll-envelopes/description/
// NOTE: Please pay special attention to the sort function. Rest not convincing but the only nlogn solution.

bool sortList(pair<int, int> &a, pair<int, int> &b) {
    return a.second == b.second ? a.first > b.first : a.second < b.second;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size();

        vector<pair<int, int>> list;

        for (int i = 0; i < len; i++) {
            list.push_back(make_pair(envelopes[i][0], envelopes[i][1]));
        }

        sort(list.begin(), list.end(), sortList);

        vector<int> dp(1, list[0].first);

        for (int i = 1; i < len; i++) {
            if (list[i].first > dp[dp.size() - 1]) {
                dp.push_back(list[i].first);
            } else {
                int start = 0;
                int end = dp.size() - 1;
                
                while(start <= end) {
                    int mid = (start + end) / 2;

                    if (dp[mid] < list[i].first) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                dp[start] = list[i].first;
            }
        }

        return dp.size();
    }
};
