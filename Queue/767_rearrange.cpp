// https://leetcode.com/problems/reorganize-string/description/

class sortQueue {
public:
    bool operator()(pair<char, int> &a, pair<char, int> &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        if (n == 0) {
            return "";
        }
        vector<int> count(26, 0);
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        
        priority_queue<pair<char,int>, vector<pair<char, int>>, sortQueue> freq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                freq.push(make_pair(i + 'a', count[i]));
            }
        }

        string rearr = "";
        bool isPos = true;
        while(!freq.empty()) {
            pair<char, int> tmp = freq.top();
            freq.pop();

            if (rearr.length() > 0 && rearr[rearr.length() - 1] == tmp.first) {
                if (freq.size() == 0) {
                    isPos = false;
                    break;
                } else {
                    pair<char, int> nextFreq = freq.top();
                    freq.pop();
                    rearr += nextFreq.first;
                    freq.push(tmp);
                    if (nextFreq.second > 1) {
                        freq.push(make_pair(nextFreq.first, nextFreq.second - 1));
                    }
                }
            } else {
                rearr += tmp.first;
                cout << tmp.first << " " << tmp.second << endl;
                if (tmp.second > 1) {
                    freq.push(make_pair(tmp.first, tmp.second - 1));
                }
            }
        }
        return isPos ? rearr : "";
    }
};
