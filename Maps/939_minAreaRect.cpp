// https://leetcode.com/problems/minimum-area-rectangle/description/
// https://leetcode.com/problems/minimum-area-rectangle/solutions/900264/intuitive-with-pictures-c-java-explanation/

int minAreaRect(vector<vector<int>>& points) {
    int n = points.size();
    map<pair<int, int>, int> counts;

    for(int i = 0; i < n; i++) {
        counts[{points[i][0], points[i][1]}] ++;
    }

    int minArea = INT_MAX;
    for (int i = 0; i < n; i++) {
        vector<int> p1 = points[i];
        for (int j = 0; j < n; j++) {
            vector<int> p2 = points[j];

            // find if p1 and p2 can be diagonal points
            pair<int, int> p3, p4;
            if ((p1[0] < p2[0] && p1[1] < p2[1]) || (p2[0] < p1[0] && p2[1] < p1[1])) {
                p3 = {p1[0], p2[1]};
                p4 = {p2[0], p1[1]};

                if (counts.find(p3) != counts.end() && counts.find(p4) != counts.end()) {
                    minArea = min(minArea, abs(p2[0] - p1[0]) * abs(p2[1] - p1[1]));
                }
            }
        }
    }

    return minArea == INT_MAX ? 0 : minArea;
}
