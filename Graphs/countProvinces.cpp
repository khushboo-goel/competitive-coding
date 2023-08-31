https://leetcode.com/problems/number-of-provinces/

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> visited(n, 0);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            provinces ++;
            deque<int> cities;
            cities.push_back(i);
            while(!cities.empty()) {
                int city = cities.front();
                cities.pop_front();
                visited[city] = 1;
                for (int j = 0; j < n; j++) {
                    if (visited[j] == 0 && isConnected[city][j] == 1) {
                        visited[j] = 1;
                        cities.push_back(j);
                    }
                }
            }
        }
    }

    return provinces;
}
