// https://leetcode.com/problems/group-anagrams/description/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> result;

    for (int i = 0; i < strs.size(); i++) {
        string sortedStr = strs[i];
        sort(sortedStr.begin(), sortedStr.end());
        if (result.find(sortedStr) == result.end()) {
            vector<string> newVec(1, strs[i]);
            result[sortedStr] = newVec;
        } else {
            result[sortedStr].push_back(strs[i]);
        }
    }

    vector<vector<string>> finalRes;
    for(unordered_map<string, vector<string>> :: iterator itr = result.begin(); itr != result.end(); itr ++) {
        finalRes.push_back(itr -> second);
    }

    return finalRes;
}
