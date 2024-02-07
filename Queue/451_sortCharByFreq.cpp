// https://leetcode.com/problems/sort-characters-by-frequency/description/
class sortQueue{
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> temp;
        for(int i = 0; i < s.length(); i++) {
            temp[s[i]] ++;
        }


        priority_queue<pair<char, int>, vector<pair<char, int>>, sortQueue> val;
        for (unordered_map<char, int> :: iterator itr = temp.begin(); itr != temp.end(); itr ++) {
            val.push(make_pair(itr -> first, itr -> second));
        }

        string res = "";
        while(!val.empty()) {
            for (int j = 0; j < val.top().second; j++) {
                res += val.top().first;
            }
            val.pop();
        }

        return res;
    }
};
