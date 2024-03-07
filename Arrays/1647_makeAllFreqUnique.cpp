// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

int minDeletions(string s) {
    int n = s.length();
    vector<int> count(26, 0);

    for(int i = 0; i < n; i++) {
        count[s[i] - 'a'] ++;
    }

    sort(count.begin(), count.end(), greater<int>());
    set<int> numberPresent;
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            numberPresent.insert(count[i]);
        }
    }

    int total = 0;

    for (int i = 1; i < 26; i++) {
        if (count[i] != 0) {
            if (count[i] == count[i - 1]) { // not strictly decreasing
                for (int j = count[i] - 1; j >= 0; j--) {
                    if(j == 0 || numberPresent.find(j) == numberPresent.end()) {
                        total += (count[i] - j);
                        numberPresent.insert(j);
                        break;
                    }
                }
            }
        }
    }
    return total;
}
