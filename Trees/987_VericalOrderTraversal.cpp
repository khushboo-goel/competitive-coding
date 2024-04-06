// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/?envType=list&envId=pcxjbubg

static bool sortList(pair<int, int> &a, pair<int, int> &b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<pair<int, int>>> levels;

    queue<pair<TreeNode*, pair<int, int>>> level;
    level.push(make_pair(root, make_pair(0, 0)));

    while(!level.empty()) {
        pair<TreeNode*, pair<int, int>> node = level.front();
        level.pop();
        int row = node.second.first;
        int col = node.second.second;
        if (levels.find(col) == levels.end()) {
            levels[col] = vector<pair<int, int>>(1, make_pair(node.first -> val, row));
        } else {
            levels[col].push_back(make_pair(node.first -> val, row));
        }
        if (node.first -> left != NULL) {
            level.push(make_pair(node.first -> left, make_pair(row + 1, col - 1)));
        }
        if (node.first -> right != NULL) {
            level.push(make_pair(node.first -> right, make_pair(row + 1, col + 1)));
        }
    }

    vector<vector<int>> result;
    for (map<int, vector<pair<int, int>>>:: iterator itr = levels.begin(); itr != levels.end(); itr++) {
        vector<pair<int, int>> test = itr -> second;
        sort(test.begin(), test.end(), sortList);
        vector<int> tmp;
        for (int i = 0; i < test.size(); i++) {
            tmp.push_back(test[i].first);
        }
        result.push_back(tmp);
    }

    return result;
}
