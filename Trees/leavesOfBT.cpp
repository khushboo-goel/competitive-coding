// https://leetcode.com/problems/find-leaves-of-binary-tree/description/

int findNodeValuesLevelWise(TreeNode* node, vector<vector<int>> &result) {
    if (node == NULL) {
        return 0;
    }
    if (node -> left == NULL && node -> right == NULL) {
        if (result.size() > 0) {
            result[0].push_back(node -> val);
        } else {
            vector<int> level(1, node -> val);
            result.push_back(level);
        }
        return 1;
    }

    int left = findNodeValuesLevelWise(node -> left, result);
    int right = findNodeValuesLevelWise(node -> right, result);

    int maxLevel = right > left ? right : left;
    if (result.size() > maxLevel) {
        result[maxLevel].push_back(node -> val);
    } else {
        vector<int> level(1, node -> val);
        result.push_back(level);
    }
    return maxLevel + 1;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }

    int resp = findNodeValuesLevelWise(root, result);
    return result;
}
