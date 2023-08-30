int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

    int count = 0;
    for(int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1' && visited[i][j] == 0) {
                count++;
                deque<pair<int, int>> nodes;
                nodes.push_back(make_pair(i, j));
                visited[i][j] = 1;
                while (!nodes.empty()){
                    pair<int, int> val = nodes.front();
                    nodes.pop_front();

                    // check all neighbour values and if not visited and zero, mark as 1;

                    if (val.first > 0 && grid[val.first - 1][val.second] == '1' && visited[val.first - 1][val.second] == 0) {
                        visited[val.first - 1][val.second] = 1;
                        nodes.push_back(make_pair(val.first - 1, val.second));
                    } 

                    if (val.first < grid.size() - 1 && grid[val.first + 1][val.second] == '1' && visited[val.first + 1][val.second] == 0) {
                        visited[val.first + 1][val.second] = 1;
                        nodes.push_back(make_pair(val.first + 1, val.second));
                    }

                    if (val.second > 0 && grid[val.first][val.second - 1] == '1' && visited[val.first][val.second - 1] == 0) {
                        visited[val.first][val.second - 1] = 1;
                        nodes.push_back(make_pair(val.first, val.second - 1));
                    }

                    if (val.second < grid[0].size() - 1 && grid[val.first][val.second + 1] == '1' && visited[val.first][val.second + 1] == 0) {
                        visited[val.first][val.second + 1] = 1;
                        nodes.push_back(make_pair(val.first, val.second + 1));
                    }
                }
            }
        }
    }

    return count;
}

// https://leetcode.com/problems/number-of-islands/description/
