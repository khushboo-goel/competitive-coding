// https://leetcode.com/problems/binary-search-tree-iterator/description/

class BSTIterator {
public:
    vector<TreeNode*> traversal;
    int currIndex;

    void inorderTraversal(TreeNode* root) {
        if (root != NULL) {
            inorderTraversal(root -> left);
            traversal.push_back(root);
            inorderTraversal(root -> right);
        }
    }

    BSTIterator(TreeNode* head) {
        inorderTraversal(head);
        currIndex = 0;
    }
    
    int next() {
        int returnVal = traversal[currIndex] -> val;
        currIndex ++;
        return returnVal;
    }
    
    bool hasNext() {
        return currIndex < traversal.size();
    }
};
