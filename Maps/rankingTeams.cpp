// https://leetcode.com/problems/rank-teams-by-votes/description/
// NOTE: custom sorting function is the only thing here to solve in this question

bool sortTeams(pair<char, vector<int>> &a, pair<char, vector<int>> &b) {
    for (int i = 0; i < a.second.size(); i++) {
        if (a.second[i] != b.second[i]) {
            return a.second[i] > b.second[i];
        }
    }

    return a.first < b.first;
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int len = votes.size();
        int teams = votes[0].length();

        if (len == 1) {
            return votes[0];
        }

        map<char, vector<int>> ranking;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < teams; j++) {
                if (ranking.find(votes[i][j]) == ranking.end()) {
                    vector<int> newArray = vector<int>(teams, 0);
                    newArray[j] = 1;
                    ranking[votes[i][j]] = newArray;
                } else {
                    ranking[votes[i][j]][j] += 1;
                }
            }
        }

        vector<pair<char, vector<int>>> orderList;
        for (map<char, vector<int>> :: iterator itr = ranking.begin(); itr != ranking.end(); itr ++) {
            orderList.push_back(make_pair(itr -> first, itr -> second));
        }

        sort(orderList.begin(), orderList.end(), sortTeams);

        string sortedTeams = "";

        for (int i = 0; i < orderList.size(); i++) {
            sortedTeams += orderList[i].first;
        }
        return sortedTeams;
    }
};
