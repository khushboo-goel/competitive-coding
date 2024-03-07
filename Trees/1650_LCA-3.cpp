// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
Node* lowestCommonAncestor(Node* p, Node * q) {
    Node* tmpP = p;
    Node* tmpQ = q;

    stack<Node*> routeP;
    while(tmpP != NULL) {
        routeP.push(tmpP);
        tmpP = tmpP -> parent;
    }

    stack<Node*> routeQ;
    while(tmpQ != NULL) {
        routeQ.push(tmpQ);
        tmpQ = tmpQ -> parent;
    }

    int len = routeP.size() > routeQ.size() ? routeQ.size() : routeP.size();
    Node* LCA = NULL;
    for (int i = 0; i < len; i++) {
        if (routeP.top() -> val == routeQ.top() -> val) {
            LCA = routeP.top();
            routeP.pop(); routeQ.pop();
        } else {
            break;
        }
    }

    return LCA;
}
