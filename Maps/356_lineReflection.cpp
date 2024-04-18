// https://leetcode.com/problems/line-reflection/
bool isReflected(vector<vector<int>>& points) {
    int n = points.size();
    set<pair<float, float>> seen;

    int maxX = INT_MIN;
    int minX = INT_MAX;

    for (int i = 0; i < n; i++) {
        maxX = max(maxX, points[i][0]);
        minX = min(minX, points[i][0]);
        seen.insert({points[i][0], points[i][1]});
    }

    float res = ((float)minX + maxX) / 2;

    for (int i = 0; i < n; i++) {
        if (seen.find({ 2 * res - points[i][0], points[i][1]}) == seen.end()) {
            return false;
        }
    }

    return true;
}
