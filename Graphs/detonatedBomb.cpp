// https://leetcode.com/problems/detonate-the-maximum-bombs/

int maximumDetonation(vector<vector<int>>& bombs) {
    int len = bombs.size();
    if (len == 0 || len == 1) {
        return len;
    }
    vector<vector<int>> graph(len, vector<int>(len, 0));

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i != j) {
                float xDist = (float)(bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]);
                float yDist = (float)(bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                float eucDis = sqrt(xDist + yDist);

                if (eucDis <= (float)bombs[i][2]) {
                    graph[i][j] = 1;
                }
                if (eucDis <= (float)bombs[j][2]) {
                    graph[j][i] = 1;
                }
            }
        }
    }
    
    int maxBombs = 1;
    for (int i = 0; i < len; i++){
        deque<int> nodes;
        vector<int> visited(len, 0);
        int count = 0;
        nodes.push_back(i);
        while(!nodes.empty()) {
            int node = nodes.front();
            nodes.pop_front();
            visited[node] = 1;
            count++;
            for (int j = 0; j < len; j++) {
                if (graph[node][j] == 1 && visited[j] == 0) {
                    nodes.push_back(j);
                    visited[j] = 1;
                }
            }
        }
        maxBombs = max(maxBombs, count);
    }
    return maxBombs;
}
