// https://leetcode.com/problems/top-k-frequent-elements/

class sortQueue{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;

        for (int i = 0; i < n; i++) {
            if (freq.find(nums[i]) != freq.end()) {
                freq[nums[i]] ++;
            } else {
                freq[nums[i]] = 1;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, sortQueue> pq;

        for (map<int, int> :: iterator itr = freq.begin(); itr != freq.end(); itr++) {
            if (pq.size() < k) {
                pq.push(make_pair(itr -> first, itr -> second));
            } else {
                pair<int, int> min = pq.top();
                if (min.second < itr -> second) {
                    pq.pop();
                    pq.push(make_pair(itr -> first, itr -> second));
                }
            }
        }

        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};
