// https://leetcode.com/problems/find-the-winner-of-an-array-game/

int getWinner(vector<int>& arr, int x) {
    if (x == 0) {
        return 0;
    }
    int maxVal = 0;
    for (int i = 0; i < arr.size(); i++) {
        maxVal = max(maxVal, arr[i]);
    }

    int currWinner = arr[0];
    int streak = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < currWinner) {
            streak++;
        } else {
            currWinner = arr[i];
            streak = 1;
        }

        if (streak == x || currWinner == maxVal) {
            return currWinner;
        }
    }

    return -1;
}
