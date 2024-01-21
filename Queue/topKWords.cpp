// https://leetcode.com/problems/top-k-frequent-words/description/

class sortQueue {
    public:
        bool operator()(pair<string, int> a, pair<string, int> b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> dict;

        for (int i = 0; i < words.size(); i++) {
            if (dict.find(words[i]) == dict.end()) {
                dict[words[i]] = 1;
            } else {
                dict[words[i]] ++;
            }
        }

        priority_queue<pair<string,int>, vector<pair<string, int>>, sortQueue> pq;
        for (map<string, int> :: iterator itr = dict.begin(); itr != dict.end(); itr++) {
            pq.push(make_pair(itr -> first, itr -> second));
        }

        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
