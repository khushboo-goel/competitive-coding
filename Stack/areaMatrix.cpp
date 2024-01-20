// https://leetcode.com/problems/maximal-rectangle/description/

int areaOfHist(vector<int> arr) {
    int n = arr.size();

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return arr[0];
    }

    int maxArea = 0;
    stack<pair<int, int>> stk;

    for (int i = 0; i < n; i++) {
        while(!stk.empty() && stk.top().first > arr[i]) {
            pair<int, int> val = stk.top();
            stk.pop();
            maxArea = max(maxArea, val.first * (stk.empty() ? i : i - stk.top().second - 1));
        }
        stk.push(make_pair(arr[i], i));
    }

    while(!stk.empty()) {
        pair<int, int> val = stk.top();
        stk.pop();
        maxArea = max(maxArea, val.first * (stk.empty() ? n : n - stk.top().second - 1));
    }

    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    int maxArea = 0;
    vector<int> hist(col, 0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            hist[j] = matrix[i][j] == '1' ? hist[j] + 1 : 0;
        }
        maxArea = max(maxArea, areaOfHist(hist));
    }

    return maxArea;
}
