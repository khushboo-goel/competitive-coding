// https://leetcode.com/problems/buildings-with-an-ocean-view/description/

vector<int> findBuildings(vector<int>& heights) {
    int n = heights.size();
    int maxSeen = 0;

    vector<int> res;

    for (int i = n - 1; i >= 0; i--) {
        if (heights[i] > maxSeen) {
            res.push_back(i);
            maxSeen = heights[i];
        }
    }

    reverse(res.begin(), res.end());
    return res;
}
