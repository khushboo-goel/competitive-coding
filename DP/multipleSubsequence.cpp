// https://leetcode.com/problems/number-of-matching-subsequences/description/
int numMatchingSubseq(string s, vector<string>& words) {
    int len = words.size();

    if (len == 0) {
        return 0;
    }

    map<char, vector<string>> dictionary;
    for (int i = 0; i < len; i++) {
        if (dictionary.find(words[i][0]) == dictionary.end()){
            vector<string> val;
            val.push_back(words[i]);
            dictionary[words[i][0]] = val;
        } else {
            dictionary[words[i][0]].push_back(words[i]);
        }
    }

    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        vector<string> copy = dictionary[s[i]];
        dictionary[s[i]] = vector<string>(0);
        for (int j = 0; j < copy.size(); j++) {
            string word = copy[j];
            int wordSize = copy[j].length();
            if (wordSize == 1) {
                result++;
            } else {
                string insertedWord = copy[j].substr(1, wordSize - 1);
                if (dictionary.find(word[1]) == dictionary.end()) {
                    vector<string> val;
                    val.push_back(insertedWord);
                    dictionary[word[1]] = val;
                }
                else {
                    dictionary[word[1]].push_back(insertedWord);
                }
            }
        }
    }

    return result;
}
