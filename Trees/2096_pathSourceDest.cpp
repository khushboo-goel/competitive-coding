// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

string startPath = "";
string destPath = "";
TreeNode* LCA(TreeNode* root, int start, int end) {
    if (root == NULL) {
        return NULL;
    }

    if (root -> val == start || root -> val == end) {
        return root;
    }

    TreeNode* left = LCA(root -> left, start, end);
    TreeNode* right = LCA(root -> right, start, end);

    if (left != NULL && right != NULL) {
        return root ;
    } else if (left != NULL) {
        return left;
    } else if (right != NULL) {
        return right;
    }

    return NULL;
}

void findPath(TreeNode* root, int start, int end, string &path) {
    if (root == NULL) {
        return;
    }
    if (root -> val == end) {
        destPath = path;
    } 
    if (root -> val == start) {
        startPath = path;
    }
    path += "L";
    findPath(root -> left, start, end, path);
    path.pop_back();
    if (startPath != "" & destPath != "") {
        return;
    }
    path += "R";
    findPath(root -> right, start, end, path);
    path.pop_back();
    return;
}
string getDirections(TreeNode* root, int startValue, int destValue) {
    TreeNode* lca = LCA(root, startValue, destValue);
    string sourcePath = "", endPath = "";
    findPath(lca, startValue, destValue, endPath);
    findPath(lca, startValue, destValue, sourcePath);
    for (int i = 0; i < startPath.size(); i++) {
        startPath[i] = 'U';
    }
    return startPath + destPath;
}
