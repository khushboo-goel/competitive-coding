// https://leetcode.com/problems/sum-of-subarray-ranges/
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    stack<int> largest;
    stack<int> smallest;

    long long sumSmallest = 0;
    long long sumLargest = 0;
    for (int i = 0; i < n; i++) {
        while(!smallest.empty() && nums[smallest.top()] >= nums[i]) {
            int node = smallest.top();
            smallest.pop();
            int left = smallest.empty() ? node + 1 : node - smallest.top();
            int right = i - node;
            long long times = left * (long long) right;
            sumSmallest += nums[node] * times;
        }

        smallest.push(i);

        while(!largest.empty() && nums[largest.top()] <= nums[i]) {
            int node = largest.top();
            largest.pop();
            int left = largest.empty() ? node + 1 : node - largest.top();
            int right = i - node;
            long long times = left * (long long) right;
            sumLargest += nums[node] * times;
        }

        largest.push(i);

    }

    while(!smallest.empty()) {
        int node = smallest.top();
        smallest.pop();
        int left = smallest.empty() ? node + 1 : node - smallest.top();
        int right = n - node;
        long long times = left * (long long) right;
        sumSmallest += nums[node] * times;
    }

    while(!largest.empty()) {
        int node = largest.top();
        largest.pop();
        int left = largest.empty() ? node + 1 : node - largest.top();
        int right = n - node;
        long long times = left * (long long) right;
        sumLargest += nums[node] * times;
    }

    return sumLargest - sumSmallest;
}
