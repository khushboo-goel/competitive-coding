// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> count;
    for(int i = 0; i < tasks.size(); i++) {
        count[tasks[i]] ++;
    }

    int minRounds = 0;
    for(unordered_map<int, int>:: iterator itr = count.begin(); itr != count.end(); itr++) {
        if (itr -> second == 1) {
            return -1;
        } else if (itr -> second % 3 == 0) {
            minRounds += itr -> second / 3;
        } else {
            minRounds += (itr -> second / 3) + 1;
        }
    }

    return minRounds;
}
