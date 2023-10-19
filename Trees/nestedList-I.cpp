// https://leetcode.com/problems/nested-list-weight-sum/

int depthSum(vector<NestedInteger>& nestedList) {
    int sum = 0;

    deque<pair<NestedInteger, int>> que;
    for (int i = 0; i < nestedList.size(); i++) {
        que.push_back(make_pair(nestedList[i], 1));
    }
    while(!que.empty()) {
        pair<NestedInteger, int> val = que.front();
        que.pop_front();
        bool isInt = (val.first).isInteger();
        if (isInt) {
            sum += ((val.first).getInteger() * val.second);
        } else {
            vector<NestedInteger> listInside = (val.first).getList();
            for (int i = 0; i < listInside.size(); i++) {
                que.push_back(make_pair(listInside[i], val.second + 1));
            }
        }
    }

    return sum;
}
