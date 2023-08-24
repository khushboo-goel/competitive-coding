class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>>graph(n, vector<int>(n, 0));

        for(int i = 0; i < relations.size(); i++) {
            graph[relations[i][0] - 1][relations[i][1] - 1] = 1;
        }

        vector<int> inBound(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                inBound[j] += graph[i][j];
            }
        }

        queue<int> nodes;
        for(int i = 0; i < n; i++) {
            if (inBound[i] == 0) {
                nodes.push(i);
            }
        }

        if (nodes.size() == 0) {
            return -1;
        }

        int sem = 0;
        int nodesVisited = 0;

        while(!nodes.empty()){
            int size = nodes.size();
            while(size > 0) {
                int currNode = nodes.front();
                nodes.pop();
                nodesVisited++;
                for(int i = 0; i < n; i++) {
                    if (graph[currNode][i] == 1 && inBound[i] == 1){
                        nodes.push(i);
                    } else if (graph[currNode][i] == 1 && inBound[i] > 1) {
                        inBound[i]--;
                    }
                }
                size --;
            }
            sem++;
        }
        return (nodesVisited == n) ? sem : -1;
    }
};

// https://leetcode.com/problems/parallel-courses/description/
