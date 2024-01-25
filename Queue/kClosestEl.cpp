// https://leetcode.com/problems/find-k-closest-elements/description/

class sortQueue{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, sortQueue> diff;

        for (int i = 0; i < arr.size(); i++) {
            if (diff.size() < k) {
                diff.push(make_pair(abs(x - arr[i]), arr[i]));
            } else {
                if (diff.top().first > abs(x - arr[i])) {
                    diff.pop();
                    diff.push(make_pair(abs(x - arr[i]), arr[i]));
                }
            }
        }

        vector<int> result;
        while(!diff.empty()) {
            pair<int, int> val = diff.top();
            diff.pop();
            result.push_back(val.second);
        }

        sort(result.begin(), result.end());
        return result;
    }
};
