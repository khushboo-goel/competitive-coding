// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
// NOTE: just convert given formula from pref = ..... to arr[i] = ... using XOR properties.
vector<int> findArray(vector<int>& pref) {
    int n = pref.size();
    vector<int> result(n, 0);

    result[0] = pref[0];
    for (int i = 1; i < n; i++) {
        result[i] = pref[i] ^ pref[i - 1];
    }

    return result;
}
