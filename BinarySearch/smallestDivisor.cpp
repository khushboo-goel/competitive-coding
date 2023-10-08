// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

int smallestDivisor(vector<int>& nums, int threshold) {
    int len = nums.size();

    int minDivisor = 1;
    int maxDivisor = INT_MIN;
    for (int i = 0; i < len; i++) {
        maxDivisor = max(maxDivisor, nums[i]);
    }

    int start = minDivisor;
    int end = maxDivisor;

    int smallestDivisor = maxDivisor;
    while(start <= end) {
        int mid = start + (end - start) / 2;

        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += ceil((float)nums[i] / mid);
        }

        if (sum > threshold) {
            start = mid + 1;
        } else {
            smallestDivisor = min(smallestDivisor, mid);
            end = mid - 1;
        }
    }

    return smallestDivisor;
}
