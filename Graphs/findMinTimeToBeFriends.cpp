// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/description/
bool sortLogs(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int findParent(int x, vector<int> list) {
    int consideredNode = x;
    while(list[consideredNode] > 0) {
        consideredNode = list[consideredNode];
    }

    return consideredNode;
}

void unionEdges(int x, int y, vector<int> &list) {
    if (abs(x) >= abs(y)) {
        list[y] = x;
        list[x] = (abs(x) + abs(y)) * (-1);
    } else {
        list[x] = y;
        list[y] = (abs(x) + abs(y)) * (-1);
    }
}

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int logLen = logs.size();
        if (logLen == 0) {
            return -1;
        }
        sort(logs.begin(), logs.end(), sortLogs);

        vector<int> parent(n, -1);
        int edgesVisited = 0;
        int latestTimestamp = logs[0][0];
        for(int i = 0; i < logLen; i++) {
            vector<int> edge = logs[i];

            int parentX = findParent(edge[1], parent);
            int parentY = findParent(edge[2], parent);

            if ((parentX != parentY) || parentX < 0){
                edgesVisited++;
                unionEdges(parentX, parentY, parent);
                if (edge[0] > latestTimestamp) {
                   latestTimestamp = edge[0]; 
                }
            }
        }

        return (edgesVisited < n - 1) ? - 1: latestTimestamp;
    }
};
