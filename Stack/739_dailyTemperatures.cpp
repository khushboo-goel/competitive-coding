// https://leetcode.com/problems/daily-temperatures/

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> stk;
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++){
        while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
            result[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }

    return result;
}
