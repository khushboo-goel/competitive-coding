// https://leetcode.com/problems/word-break/description/

// This might seem like a simple string manipulation, but it is a mixture of trie and DP
bool wordBreak(string s, vector<string>& wordDict) {
        int len = wordDict.size();
        map<string, int> dict;

        for (int i = 0; i < len; i++) {
            dict[wordDict[i]] = 1;
        }

        vector<bool> dp(s.length(), false);
        if (dict.find(s.substr(0, 1)) != dict.end()) {
            dp[0] = true;
        }

        for (int i = 1; i < s.length(); i++) {
            string tmp = "";
            for (int j = i; j >= 0; j--) {
                tmp = s[j] + tmp;
                if (dict.find(tmp) != dict.end() && (j == 0 || dp[j - 1] == true)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length() - 1];

    }
