// https://leetcode.com/problems/longest-repeating-character-replacement/description/

int characterReplacement(string s, int k) {
    int n = s.length();

    set<char> pres;
    for(int i = 0; i < n; i++) {
        pres.insert(s[i]);
    }

    int maxLen = 1;
    for(set<char> :: iterator itr = pres.begin(); itr != pres.end(); itr++) {
        int i = 0, j = 0;
        int currEl = *itr;

        int count = 0;
        while(j < n) {
            if (s[j] != currEl) {
                count++;
            }

            if (count > k) {
                if (s[i] != currEl) {
                    count--;
                }
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
    }

    return maxLen;
}
