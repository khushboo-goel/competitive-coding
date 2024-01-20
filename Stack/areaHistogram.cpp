// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// NOTE: idea wise is simple, pay attention to when the values are popped and the formula to calculate maxArea to understand better.

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return heights[0];
    }

    stack<pair<int, int>> values;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        while(!values.empty() && values.top().first > heights[i]) {
            pair<int, int> bar = values.top();
            values.pop();
            maxArea = max(maxArea, bar.first * (values.empty() ? i : i - values.top().second - 1));
        }
        values.push(make_pair(heights[i], i));
    }

    while(!values.empty()) {
        pair<int, int> bar = values.top();
        values.pop();
        maxArea = max(maxArea, bar.first * (values.empty() ? n : n - values.top().second - 1));
    }

    return maxArea;
}
