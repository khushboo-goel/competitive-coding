// https://leetcode.com/problems/longest-consecutive-sequence/description/
int longestConsecutive(vector<int>& nums) {
    int len = nums.size();
    map<int, int> freq;
    if (len == 0 || len == 1) {
        return len;
    }

    for (int i = 0; i < len; i++) {
        if (freq.find(nums[i]) == freq.end()) {
            freq[nums[i]] = 1;
        } else {
            freq[nums[i]] += 1;
        }
    }

    // create list of uniques to optimise the function
    vector<int> uniques(1, nums[0]);
    for (int i = 1; i < len; i++) {
        if (nums[i] != nums[i - 1]) {
            uniques.push_back(nums[i]);
        }
    }

    int maxLen = 1;
    for (int i = 0; i < uniques.size(); i++) {
        if (freq.find(uniques[i] - 1) == freq.end()) {
            int num = uniques[i];
            int currLen = 0;

            while(freq.find(num) != freq.end()) {
                num++;
                currLen++;
            }

            maxLen = max(maxLen, currLen);
        }
    }

    return maxLen;
}

// One more solution
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }

    sort(nums.begin(), nums.end());
    int maxLen = 1;
    int currLen = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            currLen ++;
        } else if (nums[i] != nums[i - 1]){
            currLen = 1;
        }
        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}
