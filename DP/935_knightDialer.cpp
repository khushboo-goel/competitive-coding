// https://leetcode.com/problems/knight-dialer/description/

int knightDialer(int n) {
    vector<vector<int>> permittedMoves = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    vector<int> moves(10, 0);
    int count = 10;
    for (int i = 0; i < 10; i++) {
        moves[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        vector<int> tmpMoves(10, 0);
        int tmpCount = 0;
        for (int j = 0; j < 10; j++) {
            for(int k = 0; k < permittedMoves[j].size(); k++) {
                tmpMoves[j] += moves[permittedMoves[j][k]];
                tmpMoves[j] %= 1000000007;
            }
            tmpCount = (tmpCount + tmpMoves[j]) % 1000000007;
        }
        moves = tmpMoves;
        count = tmpCount;
    }

    return count;
}
