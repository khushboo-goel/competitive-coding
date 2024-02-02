// https://leetcode.com/problems/analyze-user-website-visit-pattern/description/
static bool sortList(pair<int, string> &a, pair<int, string> &b) {
    return a.first < b.first;
}
vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    map<string, vector<pair<int, string>>> currValue;
    int n = username.size();

    for (int i = 0; i < n; i++) {
        if (currValue.find(username[i]) != currValue.end()) {
            currValue[username[i]].push_back(make_pair(timestamp[i], website[i]));
        } else {
            vector<pair<int, string>> newVector;
            newVector.push_back(make_pair(timestamp[i], website[i]));
            currValue[username[i]] = newVector;
        }
    }

    map<vector<string>, pair<string,int>> count;
    for (map<string, vector<pair<int, string>>>:: iterator itr = currValue.begin(); itr != currValue.end(); itr ++) {
        string user = itr -> first;
        vector<pair<int, string>> visited(itr -> second);
        sort(visited.begin(), visited.end(), sortList);
        for (int i = 0; i < visited.size(); i++) {
            for (int j = i + 1; j < visited.size(); j++) {
                for (int k = j + 1; k < visited.size(); k++) {
                    vector<string> pattern;
                    pattern.push_back(visited[i].second);
                    pattern.push_back(visited[j].second);
                    pattern.push_back(visited[k].second);
                    if (count.find(pattern) != count.end()) {
                        if (count[pattern].first != user){
                            pair<string, int> update = make_pair(user, count[pattern].second + 1);
                            count[pattern] = update;
                        }
                    } else {
                        count[pattern] = make_pair(user, 1);
                    }
                }
            }
        }
    }

    vector<string> pattern;
    int score = 0;
    for (map<vector<string>, pair<string,int>>:: iterator itr = count.begin(); itr != count.end(); itr ++) {
        int currScore = itr -> second.second;
        if (currScore > score) {
            score = currScore;
            pattern = itr -> first;
        }
    }

    return pattern;
    
}
