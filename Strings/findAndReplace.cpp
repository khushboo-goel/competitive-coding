// https://leetcode.com/problems/find-and-replace-in-string/

static bool sortList(pair<int, pair<string, string>> a, pair<int, pair<string, string>> b) {
    return a.first < b.first;
}
string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    string newString = s;
    int replacements = indices.size();
    int n = s.size();

    vector<pair<int, pair<string, string>>> inputs;
    for(int i = 0; i < replacements; i++) {
        inputs.push_back(make_pair(indices[i], make_pair(sources[i], targets[i])));
    }

    sort(inputs.begin(), inputs.end(), sortList);

    for (int i = replacements - 1; i >= 0; i--) {
        string check = inputs[i].second.first;
        int index = inputs[i].first;
        string sub = s.substr(index, check.length());

        if (sub == check) {
            string update = inputs[i].second.second;
            string newStr = newString.substr(0, index) + update + newString.substr(check.size() + index, newString.length() - check.size() - index);
            newString = newStr;
        }
    }

    return newString;
}
