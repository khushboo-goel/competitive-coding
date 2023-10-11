// https://leetcode.com/problems/design-snake-game/description/
// NOTE: 1. Idea here is to consider snake length as zero while you setup the class. 2. Tail needs to move first before checking if it bites itself.
class SnakeGame {
public:
    map<char, pair<int, int>> directions = {
        { 'U', make_pair(-1, 0) },
        { 'D', make_pair(1, 0) },
        { 'R', make_pair(0, 1) },
        { 'L', make_pair(0, -1)},
    };

    deque<pair<int, int>> board;
    map<pair<int, int>, bool> snake;
    deque<pair<int, int>> snakeMove;
    int score;
    pair<int, int> currPos;
    int w;
    int h;

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;

        for (int i = 0; i < food.size(); i++) {
            board.push_back(make_pair(food[i][0], food[i][1]));
        }

        score = 0;
        currPos = make_pair(0, 0);
        snakeMove.push_front(currPos);
        snake[currPos] = false;
    }
    
    int move(string direction) {
        int len = direction.size();
        pair<int, int> newPos = directions[direction[0]];
        if (currPos.first + newPos.first < 0 || currPos.first + newPos.first >= h) {
            return -1;
        } else if (currPos.second + newPos.second < 0 || currPos.second + newPos.second >= w) {
            return -1;
        } else {
            pair<int, int> topFood = board.front();
            currPos = make_pair(currPos.first + newPos.first, currPos.second + newPos.second);
            if (topFood.first == currPos.first && topFood.second == currPos.second) {
                score += 1;
                board.pop_front();
                if (snake[currPos] == true) {
                    return -1;
                }
                snakeMove.push_front(currPos);
                snake[currPos] = true;
            } else {
                pair<int, int> tailPos = snakeMove.back();
                snakeMove.pop_back();
                snake[tailPos] = false;
                if (snake[currPos] == true) {
                    return -1;
                }
                snakeMove.push_front(currPos);
                snake[currPos] = true;
            }
            return score;
        }

        return -1;  
    }
};
