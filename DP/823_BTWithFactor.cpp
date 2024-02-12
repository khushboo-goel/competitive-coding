// https://leetcode.com/problems/binary-trees-with-factors/description/
int numFactoredBinaryTrees(vector<int>& arr) {
    int n = arr.size();
    int mod = 1000000007;
    if (n == 1) {
        return 1;
    }

    sort(arr.begin(), arr.end());
    unordered_map<int, int> found;
    for(int i = 0; i < n; i++) {
        found[arr[i]] = i;
    }
    int sum = 1;
    vector<long long> dp(n, 1);
    for(int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int val = (arr[i] % arr[j] == 0) ? arr[i] / arr[j] : 0;
            if (found.find(val) != found.end()) {
                dp[i] += (dp[j] * dp[found[val]]);
            }
        }
        sum += dp[i] % mod;
        sum = sum % mod;
    }

    return sum;
}
