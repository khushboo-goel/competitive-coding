// https://leetcode.com/problems/odd-even-jump/description/

int oddEvenJumps(vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || n == 1) {
        return n;
    }

    vector<pair<bool, bool>> dp(n, { false, false });
    dp[n - 1].first = true;
    dp[n - 1].second = true;
    int count = 1;
    map<int, int> greaterEl;
    greaterEl[arr[n - 1]] = n - 1;
    
    for (int i = n - 2; i >= 0; i--) {
        map<int, int> :: iterator minIn = greaterEl.lower_bound(arr[i]);
        map<int, int> :: iterator maxIn = greaterEl.upper_bound(arr[i]);

        if (maxIn != greaterEl.begin()) {
            maxIn--;
            if (dp[maxIn -> second].first == true) {
                dp[i].second = true;
            }
        }
        if (minIn != greaterEl.end() && dp[minIn -> second].second == true) {
            dp[i].first = true;
            count++;
        }
        greaterEl[arr[i]] = i;
    }

    return count;
}
