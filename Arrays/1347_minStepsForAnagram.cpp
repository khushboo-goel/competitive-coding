// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

int minSteps(string s, string t) {
    int count[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a'] ++;
        count[t[i] - 'a'] --;
    }

    int minSteps = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] < 0) {
            minSteps += abs(count[i]);
        }
    }

    return minSteps;
}
