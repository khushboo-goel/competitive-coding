// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/

TreeNode* recoverFromPreorder(string traversal) {
    vector<pair<int, int>> nodes;
    int count = 0;
    string val = "";
    for (int i = 0; i < traversal.length(); i ++) {
        if (traversal[i] == '-') {
            if (val != "") {
                nodes.push_back(make_pair(stoi(val), count));
                count = 0;
                val = "";
            }
            count ++;
        } else {
            val += traversal[i];
        }
    }

    if (val != "") {
        nodes.push_back(make_pair(stoi(val), count));
        count = 0;
        val = "";
    }

    TreeNode* root = new TreeNode(nodes[0].first);
    stack<pair<TreeNode*, int>> lastVisitedNode;
    lastVisitedNode.push(make_pair(root, 0));
    
    for (int i = 1; i < nodes.size(); i++) {
        pair<int, int> currNode = nodes[i];
        pair<TreeNode*, int> lastLevel = lastVisitedNode.top();

        if (currNode.second > lastLevel.second) {
            TreeNode* newNode = new TreeNode(currNode.first);
            lastLevel.first -> left = newNode;
            lastVisitedNode.push(make_pair(newNode, currNode.second));
        } else {
            while(!lastVisitedNode.empty() && lastVisitedNode.top().second >= currNode.second) {
                lastVisitedNode.pop();
            }
            TreeNode* newNode = new TreeNode(currNode.first);
            pair<TreeNode*, int> topLevel = lastVisitedNode.top();
            topLevel.first -> right = newNode;
            lastVisitedNode.push(make_pair(newNode, currNode.second));
        }
    }
    return root;
}
