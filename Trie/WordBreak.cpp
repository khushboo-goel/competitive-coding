// https://github.com/khushboo-goel/competitive-coding/blob/main/DP/WordBreak.cpp


// Trie and DP based solution
struct trie {
    bool end;
    vector<trie*> next;
    trie() {
        end = false;
        next = vector<trie*>(26, NULL);
    }
};

class Solution {
public:
    trie* createDict(vector<string> wordList) {
        int n = wordList.size();
        trie* dict = new trie();

        for (int i = 0; i < wordList.size(); i++) {
            trie* tmp = dict;
            for (int j = 0; j < wordList[i].size(); j++) {
                if(tmp -> next[wordList[i][j] - 'a'] == NULL) {
                    trie* node = new trie();
                    tmp -> next[wordList[i][j] - 'a'] = node;
                    
                }
                if (j == wordList[i].size() - 1) {
                    tmp -> next[wordList[i][j] - 'a'] -> end = true;
                }
                tmp = tmp -> next[wordList[i][j] - 'a'];
            }
        }

        return dict;
    }
    bool findInDict(string s, trie* dict) {
        trie* tmp = dict;
        for (int i = 0; i < s.length(); i++) {
            tmp = tmp -> next[s[i] - 'a'];
            if (tmp == NULL) {
                return false;
            }
        }

        return tmp -> end == true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        trie* dict = createDict(wordDict);
        vector<bool> dp(s.length(), false);

        for (int i = 0; i < s.length(); i++) {
            string tmp = "";
            for (int j = i; j >= 0; j--) {
                tmp = s[j] + tmp;
                cout << tmp << endl;
                if ((j == 0 || dp[j - 1] == true) && findInDict(tmp, dict)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length() - 1];
    }
};
