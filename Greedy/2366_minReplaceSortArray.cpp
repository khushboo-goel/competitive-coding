// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/

long long minimumReplacement(vector<int>& nums) {
    long long count = 0;
    int n = nums.size();
    int minSeen = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        minSeen = min(minSeen, nums[i]);
        if (nums[i] > minSeen) {
            long long stepsTaken = ceil((nums[i] + minSeen - 1LL) / minSeen);
            count += (stepsTaken - 1);
            minSeen = nums[i] / stepsTaken;
        }
    }

    return count;
}
