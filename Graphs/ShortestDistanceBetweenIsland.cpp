// https://leetcode.com/problems/shortest-bridge/description/
int shortestBridge(vector<vector<int>>& grid) {
    int length = grid.size();
    int breadth = grid[0].size();

    deque<pair<int, int>> points;

    for(int i = 0; i < length; i++) {
        bool found = false;;
        for(int j = 0; j < breadth; j++){
            if (grid[i][j] == 1) {
                points.push_back(make_pair(i, j));
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // find two different islands using one bfs
    while(!points.empty()) {
        int size = points.size();
        while(size > 0) {
            pair<int, int> currPoint = points.front();
            points.pop_front();
            // left neighbour
            if (currPoint.second != 0 && grid[currPoint.first][currPoint.second - 1] == 1) {
                points.push_back(make_pair(currPoint.first, currPoint.second - 1));
            }
            // right neighbour

            if (currPoint.second != breadth - 1 && grid[currPoint.first][currPoint.second + 1] == 1) {
                points.push_back(make_pair(currPoint.first, currPoint.second + 1));
            }

            // top neighbour
            if (currPoint.first != 0 && grid[currPoint.first - 1][currPoint.second] == 1) {
                points.push_back(make_pair(currPoint.first - 1, currPoint.second));
            }

            // bottom neighbour
            if (currPoint.first != length - 1 && grid[currPoint.first + 1][currPoint.second] == 1) {
                points.push_back(make_pair(currPoint.first + 1, currPoint.second));
            }

            grid[currPoint.first][currPoint.second] = 2;
            size --;
        }
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < breadth; j++) {
            if (grid[i][j] == 2) {
                points.push_back(make_pair(i, j));
            }
        }
    }

    int oneFlips = 0;
    while(!points.empty()) {
        int size = points.size();
        while(size > 0) {
            pair<int, int> currPoint = points.front();
            points.pop_front();
            if ()
            grid[currPoint.first][currPoint.second] = -1;
            // left neighbour
            if (currPoint.second != 0) {
                if (grid[currPoint.first][currPoint.second - 1] == 0) {
                    points.push_back(make_pair(currPoint.first, currPoint.second - 1));
                } else if (grid[currPoint.first][currPoint.second - 1] == 1) {
                    return oneFlips;
                }
            }
            // right neighbour

            if (currPoint.second != breadth - 1){
                if (grid[currPoint.first][currPoint.second + 1] == 0) {
                    points.push_back(make_pair(currPoint.first, currPoint.second + 1));
                } else if (grid[currPoint.first][currPoint.second + 1] == 1) {
                    return oneFlips;
                }
            }

            // top neighbour
            if (currPoint.first != 0){
                if (grid[currPoint.first - 1][currPoint.second] == 0) {
                    points.push_back(make_pair(currPoint.first - 1, currPoint.second));
                } else if (grid[currPoint.first - 1][currPoint.second] == 1) {
                    return oneFlips;
                }
            }

            // bottom neighbour
            if (currPoint.first != length - 1){
                if(grid[currPoint.first + 1][currPoint.second] == 0) {
                    points.push_back(make_pair(currPoint.first + 1, currPoint.second));
                } else if (grid[currPoint.first + 1][currPoint.second] == 1) {
                    return oneFlips;
                }
            }
            size--;
        }
        oneFlips++;
    }

    return oneFlips;
}
