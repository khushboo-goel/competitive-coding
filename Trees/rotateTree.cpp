// https://leetcode.com/problems/binary-tree-upside-down/
TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return root;
    }

    if (root -> left == NULL && root -> right == NULL) {
        return root;
    }

    TreeNode* left = upsideDownBinaryTree(root -> left);
    TreeNode* right = upsideDownBinaryTree(root -> right);

    root -> left -> left = root -> right;
    root -> left -> right = root;
    root -> left = NULL;
    root -> right = NULL;

    return left;

}
