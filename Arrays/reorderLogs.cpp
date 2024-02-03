// https://leetcode.com/problems/reorder-data-in-log-files/description/

static bool sortLog(pair<string, string> &a, pair<string, string> &b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    }
vector<string> reorderLogFiles(vector<string>& logs) {
    int n = logs.size();
    vector<string> digitLog;
    vector<pair<string, string>> letterLog;

    for (int i = 0; i < n; i++) {
        string id = "";
        int ptr;
        for (ptr = 0; ptr < logs[i].size(); ptr++) {
            if (logs[i][ptr] == ' ') {
                break;
            } else {
                id += logs[i][ptr];
            }
        }
        if (logs[i][ptr + 1] - '0' < 10) {
            digitLog.push_back(logs[i]);
        } else {
            letterLog.push_back(make_pair(id, logs[i].substr(ptr + 1, logs[i].length() - ptr - 1)));
        }
    }
    sort(letterLog.begin(), letterLog.end(), sortLog);

    vector<string> result;
    for (int i = 0; i < letterLog.size(); i++) {
        result.push_back(letterLog[i].first + " " + letterLog[i].second);
    }

    for (int i = 0; i < digitLog.size(); i++) {
        result.push_back(digitLog[i]);
    }

    return result;
}
