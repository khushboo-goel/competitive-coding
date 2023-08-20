class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int len = books.size();

        if (len == 1) {
            return books[0][1];
        }

        // using 1D array
        vector<int> dp(len + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= len; i++) {
            int totalWidth = 0;
            int maxHeight = 0;
            int j = i;
            dp[i] = dp[i - 1] + books[i - 1][1];
            for(; j > 0; j--) {
                if (totalWidth + books[j - 1][0] <= shelfWidth) {
                    totalWidth = totalWidth + books[j - 1][0];
                    maxHeight = max(maxHeight, books[j - 1][1]);
                    dp[i] = min(dp[i], dp[j - 1] + maxHeight);
                } else {
                    break;
                }
            }
        }

        return dp[len];
    }
};
