// https://leetcode.com/problems/minimum-number-of-keypresses/description/
int minimumKeypresses(string s) {
    vector<int> count(26, 0);

    for (int i = 0; i < s.length(); i++){
        count[s[i] - 'a'] ++;
    }

    sort(count.rbegin(), count.rend());
    int totalPress = 0;
    for (int i = 0; i < 26; i++){
        if (i < 9) {
            totalPress += (count[i]);
        } else if (i < 18) {
            totalPress += (2 * count[i]);
        } else {
            totalPress += (3 * count[i]);
        }
    }

    return totalPress;
}
