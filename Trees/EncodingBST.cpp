// https://leetcode.com/problems/serialize-and-deserialize-bst/description/
// NOTE: need to find best way to write the tree (inorder is useless) and rest should be good.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
string preOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return "";
    }

    return preOrderTraversal(root -> left)+ preOrderTraversal(root -> right) + "," + to_string(root -> val);
}

vector<int> nodesFromString(string data){
    int len = data.length();
    vector<int> res;
    string node = "";
    for (int i = 0; i < len; i++) {
        if (data[i] == ',' && node != "") {
            res.push_back(stoi(node));
            node = "";
        } else if (data[i] != ','){
            node += data[i];
        }
        if (i == len - 1 && node != "") {
            res.push_back(stoi(node));
            node = "";
        }
    }

    return res;
}

TreeNode* createTreeFromPreOrder(vector<int> nodes) {
    if (nodes.size() < 1) {
        return NULL;
    }
    TreeNode* root = new TreeNode();
    int rootVal = nodes[nodes.size() - 1];
    root -> val = rootVal;
    if (nodes.size() == 1) {
        return root;
    }

    int i;
    for (i = 0; i < nodes.size() - 1; i++) {
        if (nodes[i] > rootVal) {
            break;
        }
    }
    
    root -> left = createTreeFromPreOrder({nodes.begin(), nodes.begin() + i});
    root -> right = createTreeFromPreOrder({nodes.begin() + i, nodes.end() - 1});

    return root;
}

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string pre = preOrderTraversal(root);
        return pre;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nodes = nodesFromString(data);
        return createTreeFromPreOrder(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
