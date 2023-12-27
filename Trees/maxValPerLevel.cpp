// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

vector<int> largestValues(TreeNode* root) {
    vector<int> result;

    if (root == NULL) {
        return result;
    }
    queue<TreeNode*> traversalQ;
    traversalQ.push(root);

    int maximum;
    while(!traversalQ.empty()) {
        int size = traversalQ.size();
        maximum = INT_MIN;
        while(size > 0) {
            TreeNode* node = traversalQ.front();
            traversalQ.pop();
            maximum = max(maximum, node -> val);
            if (node -> left != NULL) {
                traversalQ.push(node -> left);
            }
            if (node -> right != NULL) {
                traversalQ.push(node -> right);
            }
            size--;
        }
        result.push_back(maximum);
    }

    return result;
}
