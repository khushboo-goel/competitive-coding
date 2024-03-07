// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
int minOperations(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> count;
    for(int i = 0; i < n; i++){
        count[nums[i]] ++;
    }

    int total = 0;
    for (unordered_map<int, int> :: iterator itr = count.begin(); itr != count.end(); itr++) {
        if (itr -> second == 1) {
            return -1;
        }

        total += (itr -> second) % 3 == 0 ? (itr -> second) / 3 : ((itr -> second) / 3) + 1;
    }

    return total;
}
