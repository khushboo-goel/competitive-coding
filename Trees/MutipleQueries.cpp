// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/
class Solution {
public:
    void findHeightPreTraversal(TreeNode* root, vector<int>& height, int currLevel, int& maxLevel) {
        if (root == NULL) {
            return;
        }
        height[root -> val] = maxLevel;
        maxLevel = max(currLevel, maxLevel);
        int level = currLevel + 1;

        findHeightPreTraversal(root -> left, height, level, maxLevel);
        findHeightPreTraversal(root -> right, height, level, maxLevel);

    }

    void findHeightPostTraversal(TreeNode* root, vector<int>& height, int currLevel, int& maxLevel) {
        if (root == NULL) {
            return;
        }

        height[root -> val] = max(height[root -> val], maxLevel);
        int level = currLevel + 1;
        maxLevel = max(maxLevel, currLevel);

        findHeightPostTraversal(root -> right, height, level, maxLevel);
        findHeightPostTraversal(root -> left, height, level, maxLevel);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int querySize = queries.size();
        vector<int> height(100006, 0);

        int maxLevel = 0;
        findHeightPreTraversal(root, height, 0, maxLevel);
        maxLevel = 0;
        findHeightPostTraversal(root, height, 0, maxLevel);

        vector<int> response;
        for (int i = 0; i < querySize; i++){
            response.push_back(height[queries[i]]);
        }

        return response;
    }
};
