vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int n = candies.size();
    vector<bool> values(n, false);

    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        max = (candies[i] > max) ? candies[i] : max;
    }

    for (int i = 0; i < n ; i++) {
        if (candies[i] + extraCandies >= max) {
            values[i] = true;
        } 
    }

    return values;
}

// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=study-plan-v2&envId=leetcode-75
