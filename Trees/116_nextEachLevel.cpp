// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/?envType=list&envId=pcxjbubg

Node* connect(Node* root) {
    if (root == NULL) {
        return root;
    }
    queue<Node*> nodes;
    nodes.push(root);
    while(!nodes.empty()) {
        int size = nodes.size();
        while(size > 0) {
            Node* currNode = nodes.front();
            nodes.pop();
            size--;
            if (size > 0) {
                currNode -> next = nodes.front();
            }
            if (currNode -> left) {
                nodes.push(currNode -> left);
            }
            if (currNode -> right) {
                nodes.push(currNode -> right);
            }
        }
    }
    return root;
}
