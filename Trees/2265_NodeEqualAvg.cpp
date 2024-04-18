// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

pair<int, int> average(TreeNode* root, int &count) {
    if (root == NULL) {
        return {0, 0};
    }
    if (root -> left == NULL && root -> right == NULL) {
        count++;
        return { root -> val, 1};
    }

    pair<int, int> left = average(root -> left, count);
    pair<int, int> right = average(root -> right, count);

    if (left.second == 0 && right.second == 0) {
        return { root -> val, 1};
    } else {
        int sum = right.first + root -> val + left.first;
        int cnt = right.second + left.second + 1;
        if ((sum/cnt) == root -> val) {
            count++;
        }
        return {sum, cnt};
    }
}
int averageOfSubtree(TreeNode* root) {
    int count = 0;
    if (root == NULL) {
        return 0;
    }

    average(root, count);

    return count;
}
