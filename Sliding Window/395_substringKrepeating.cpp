// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
int longestSubstring(string s, int x) {
    int n = s.length();
    set<char> uniques;
    for (int i = 0; i < n; i++) {
        uniques.insert(s[i]);
    }

    int uniqueLetters = uniques.size();

    int maxLen = 0;
    for (int i = 1; i <= uniqueLetters; i++) {
        vector<int> count(26, 0);
        int j = 0, k = 0;
        int unique = 0;
        while(k < n) {
            if (count[s[k] - 'a'] == 0) {
                unique++;
            }
            count[s[k] - 'a']++;
            while(unique > i) {
                count[s[j] - 'a']--;
                if (count[s[j] - 'a'] == 0) {
                    unique--;
                }
                j++;
            }

            bool isPos = true;
            for (int t = 0; t < 26; t++) {
                if (count[t] > 0 && count[t] < x) {
                    isPos = false;
                    break;
                }
            }

            if (isPos) {
                maxLen = max(maxLen, k - j + 1);
            }
            k++;
        }
    }

    return maxLen;
}
