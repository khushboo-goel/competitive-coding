// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
void createLeavesList(TreeNode* root, set<int> &result) {
    if (root == NULL) {
        return;
    }
    if (root -> left == NULL && root -> right == NULL) {
        result.insert(root -> val);
    }

    createLeavesList(root -> left, result);
    createLeavesList(root -> right, result);
    return;
}

int findSecondMinimumValue(TreeNode* root) {
    set<int> leaves;
    if (root == NULL) {
        return -1;
    }
    if (root -> left == NULL && root -> right == NULL) {
        return -1;
    }

    createLeavesList(root, leaves);

    if (leaves.size() == 1) {
        return -1;
    } else {
        auto p = leaves.begin();
        return *(++p);
    }
}
