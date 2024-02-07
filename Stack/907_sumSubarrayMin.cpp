// https://leetcode.com/problems/sum-of-subarray-minimums/description/

int sumSubarrayMins(vector<int>& arr) {
    int MOD = 1000000007;
    int n = arr.size();
    stack<int> temp;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        while(!temp.empty() && arr[temp.top()] > arr[i]) {
            int val = temp.top();
            temp.pop();
            int left = temp.empty() ? val + 1 : val - temp.top();
            int right = i - val;
            long long factor = (left * (long long)right) % MOD;
            sum = (sum + ((long long)arr[val] * factor) % MOD)% MOD;
        }
        temp.push(i);
    }

    while(!temp.empty()) {
        int val = temp.top();
        temp.pop();
        int left = temp.empty() ? val + 1 : val - temp.top();
        int right = n - val;
        long long factor = (left * (long long)right) % MOD;
        sum = (sum + ((long long)arr[val] * factor) % MOD)% MOD;
    }

    return (int)sum;
}
