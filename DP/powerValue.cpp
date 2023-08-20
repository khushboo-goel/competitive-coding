bool compare(vector<int> a, vector<int> b) {
    if (a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> dp(1001, 0);
        dp[0] = 0;
        dp[1] = 3;
        dp[2] = 1;

        for(int i = 3; i <= hi; i++) {
            if (i % 2 == 0) {
                dp[i] = dp[i / 2] + 1;
            } else {
                int steps = 1;
                int val = 3 * i + 1;
                while(val >= i) {
                    if (val % 2 == 0) {
                        val /= 2;
                    } else {
                        val = 3 * val + 1;
                    }
                    steps++;
                }
                dp[i] = steps + dp[val];
            }
        }

        vector<vector<int>> rearrange;
        for(int i = lo; i <= hi; i++){
            vector<int> tmp(2, 0);
            tmp[0] = i;
            tmp[1] = dp[i];
            rearrange.push_back(tmp);
        }

        sort(rearrange.begin(), rearrange.end(), compare);

        return rearrange[k - 1][0];
    }
};

// https://leetcode.com/problems/sort-integers-by-the-power-value/description/
