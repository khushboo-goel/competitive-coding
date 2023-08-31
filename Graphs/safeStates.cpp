// https://leetcode.com/problems/find-eventual-safe-states/
// NOTE: Trick here is to invert the graph and rest is simple bfs or dfs

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<vector<int>> modGraph(n, vector<int>(0));
    vector<int> indegree(n, 0);

    for(int i = 0; i < n; i++){
        for (int j = 0; j < graph[i].size(); j++){
            modGraph[graph[i][j]].push_back(i);
            indegree[i]++;
        }
    }

    deque<int> nodes;
    for(int i = 0; i < n; i++){
        if (indegree[i] == 0) {
            nodes.push_back(i);
        }
    }

    vector<int> res;
    while(!nodes.empty()) {
        int size = nodes.size();
        while(size > 0) {
            int vertex = nodes.front();
            nodes.pop_front();
            res.push_back(vertex);
            size --;
            for (int i = 0; i < modGraph[vertex].size(); i++) {
                indegree[modGraph[vertex][i]] --;
                if (indegree[modGraph[vertex][i]] == 0) {
                    nodes.push_back(modGraph[vertex][i]);
                }
            }
        } 
    }

    sort(res.begin(), res.end());

    return res;
}
