struct Trie {
    vector<string> words;
    vector<Trie*> next;
    Trie() {
        next = vector<Trie*> (26, NULL);
    }
};
class Solution {
private:
    Trie* createTrie(vector<string> words) {
        Trie* root = new Trie();
        for(int i = 0; i < words.size(); i++) {
            int len = words[i].length();
            Trie* tmp = root;

            for (int j = 0; j < len; j++) {
                if (tmp -> next[words[i][j] - 'a'] == NULL) {
                    Trie* newNode = new Trie();
                    (newNode -> words).push_back(words[i]);
                    tmp -> next[words[i][j] - 'a'] = newNode;
                } else {

                    (tmp -> next[words[i][j] - 'a'] -> words).push_back(words[i]);
                }
                tmp = tmp -> next[words[i][j] - 'a'];
            }
        }

        return root;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* dictionary = createTrie(products);
        vector<vector<string>> result;

        Trie* node = dictionary;
        for (int i = 0; i < searchWord.length(); i++) {
            if (node == NULL) {
                vector<string> list(0);
                result.push_back(list);
            }
            else { 
                if (node -> next[searchWord[i] - 'a'] == NULL) {
                    vector<string> list(0);
                    result.push_back(list);
                } else {
                    vector<string> words = node -> next[searchWord[i] - 'a'] -> words;
                    sort(words.begin(), words.end());
                    vector<string> subarray;
                    for (int j = 0; j < 3 && j < words.size(); j++) {
                        subarray.push_back(words[j]);
                    }
                    result.push_back(subarray);
                }
                node = node -> next[searchWord[i] - 'a'];
            }
        }

        return result;
    }
};
