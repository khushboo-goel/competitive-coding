int makeConnected(int n, vector<vector<int>>& connections) {
    int len = connections.size();

    if (len + 1 < n) {
        return -1;
    }

    vector<vector<int>> graph(n, vector<int>(0));
    vector<int> indegree(n, 0);
    for(int i = 0; i < len; i++) {
        graph[connections[i][0]].push_back(connections[i][1]);
        graph[connections[i][1]].push_back(connections[i][0]);
    }

    vector<int> visited(n, 0);
    int disconnNetworks = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            disconnNetworks ++;
            deque<int> nodes;
            nodes.push_back(i);
            visited[i] = 1;
            while(!nodes.empty()) {
                int computer = nodes.front();
                nodes.pop_front();
                for(int i = 0; i < graph[computer].size(); i++) {
                    if (visited[graph[computer][i]] == 0) {
                        visited[graph[computer][i]] = 1;
                        nodes.push_back(graph[computer][i]);
                    }
                }
            }
        }
    }
    return disconnNetworks - 1;
}

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
