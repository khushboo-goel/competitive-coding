bool compare(string a, string b) {
    return a.length() < b.length();
}
bool predecessor(string a, string b) {
    int lenA = a.length();
    int lenB = b.length();

    if (lenA + 1 != lenB) {
        return false;
    }

    int count = 0;
    int first = 0;
    int sec = 0;
    while(sec < lenB) {
        if (b[sec] == a[first]){
            first ++;
            sec++;
        } else {
            count++;
            sec++;
        }
    }
    return (count == 1);
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        if (len == 1) {
            return 1;
        }
        sort(words.begin(), words.end(), compare);
        vector<int> dp(len + 1, 1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= len; i++) {
            for (int j = i - 1; j > 0; j--) {
                if (predecessor(words[j - 1], words[i - 1])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxlen = INT_MIN;
        for(int i = 0; i <= len; i++) {
            maxlen = max(maxlen, dp[i]);
        }

        return maxlen;
    }
};

// https://leetcode.com/problems/longest-string-chain/description/
