bool predecessor(string a, string b) {
    if (a.length() <= b.length() || a.length() - b.length() > 1) {
        return false;
    }

    int lenA = a.length();
    int lenB = b.length();

    int i = 0, j = 0;
    int countDiff = 0;
    while(i < lenA && j < lenB) {
        if (a[i] != b[j]) {
            countDiff ++;
            i++;
        } else {
            i++; j++;
        }
    }
    if (i < lenA) {
        countDiff += (lenA - i);
    }
    if (j < lenB) {
        countDiff += (lenB - j);
    }
    return (countDiff == 1);
}
static bool sortList(string &a, string &b) {
    return a.length() < b.length();
}
int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(), sortList);

    vector<int>dp(n + 1, 1);
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--){
            if (predecessor(words[i], words[j])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxVal = INT_MIN;
    for(int i = 1; i <= n; i++) {
        maxVal = max(maxVal, dp[i]);
    }

    return maxVal;
}
