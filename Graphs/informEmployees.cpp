// Note: Since the relationship is sparse graph, better to do adjacency list rather than matrix.
// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    if (n == 0) {
        return 0;
    }
    vector<vector<int>> graph(n, vector<int>(0));
    
    // created a graph of relations
    for(int i = 0; i < n; i ++) {
        if (i != headID) {
            graph[manager[i]].push_back(i);
        }
    }

    deque<pair<int, int>> empSeq;
    for(int i = 0; i < n; i++) {
        if (manager[i] == headID) {
            empSeq.push_back(make_pair(i, informTime[headID]));
        }
    }

    int totalTime = 0;

    while(!empSeq.empty()) {
        int size = empSeq.size();
        while(size > 0) {
            pair<int, int> emp = empSeq.front();
            empSeq.pop_front();
            for (int i = 0; i < graph[emp.first].size(); i++) {
                empSeq.push_back(make_pair(graph[emp.first][i], emp.second + informTime[emp.first]));
            }
            totalTime = totalTime > emp.second ? totalTime : emp.second;
            size --;
        }
    }

    return totalTime;

}
