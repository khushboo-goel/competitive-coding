/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool retDisjointForest(TreeNode* root, bool isHeadDeleted, map<int, bool> isDeleted, vector<TreeNode*> &result) {
        if (root == NULL) {
            return true;
        }
            // if node itself is deleted
        if (isDeleted.find(root -> val) != isDeleted.end()){
            bool isLeftDeleted = retDisjointForest(root -> left, true, isDeleted, result);
            bool isRightDeleted = retDisjointForest(root -> right, true, isDeleted, result);
            root -> left = NULL;
            root -> right = NULL;
            return true;
        } else {
            if (isHeadDeleted){
                result.push_back(root);
            }
            bool isLeftDeleted = retDisjointForest(root -> left, false, isDeleted, result);
            bool isRightDeleted = retDisjointForest(root -> right, false, isDeleted, result);
            root -> left = isLeftDeleted ? NULL : root -> left;
            root -> right = isRightDeleted ? NULL : root -> right;
            return false;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<int, bool> isDeleted;
        int len = to_delete.size();
        vector<TreeNode*> result;

        for(int i = 0; i < len; i++) {
            isDeleted[to_delete[i]] = true;
        }

        retDisjointForest(root, true, isDeleted, result);

        return result;
    }
};

// https://leetcode.com/problems/delete-nodes-and-return-forest/description/
