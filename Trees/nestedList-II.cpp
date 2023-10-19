// https://leetcode.com/problems/nested-list-weight-sum-ii/

int depthSumInverse(vector<NestedInteger>& nestedList) {
    int sumVal = 0;
    int maxDepth = 0;
    vector<int> intVals;

    deque<pair<NestedInteger, int>> q;

    for (int i = 0; i < nestedList.size(); i++) {
        q.push_back(make_pair(nestedList[i], 1));
    }

    while(!q.empty()) {
        pair<NestedInteger, int> val = q.front();
        q.pop_front();
        maxDepth = max(maxDepth, val.second);

        bool isInt = (val.first).isInteger();
        if (isInt) {
            int intVal = (val.first).getInteger();
            intVals.push_back(intVal);
            sumVal += (intVal * val.second);
        } else {
            vector<NestedInteger> listInside = (val.first).getList();
            for (int i = 0; i < listInside.size(); i++) {
                q.push_back(make_pair(listInside[i], val.second + 1));
            }
        }
    }

    int maxDepthSum = 0;
    for (int i = 0; i < intVals.size(); i++) {
        maxDepthSum += (maxDepth + 1) * intVals[i];
    }

    return maxDepthSum - sumVal;
}
