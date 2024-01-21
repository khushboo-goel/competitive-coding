// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

struct TrieNode {
    bool endOfWord;
    vector<TrieNode*> next;
    TrieNode() {
        endOfWord = false;
        next = vector<TrieNode*> (26, NULL);
    }
};
class WordDictionary {
public:
    TrieNode* dict;
    WordDictionary(){
        dict = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* head = dict;
        for (int i = 0; i < word.length(); i++) {
            if (head -> next[word[i] - 'a'] == NULL) {
                TrieNode* node = new TrieNode();
                if (i == word.length() - 1) {
                    node -> endOfWord = true;
                }
                head -> next[word[i] - 'a'] = node;
            } else {
                if (i == word.length() - 1) {
                    head -> next[word[i] - 'a'] -> endOfWord = true;
                }
            }
            head = head -> next[word[i] - 'a'];
        }
    }
    bool searchPartial(string word, TrieNode* root) {
        TrieNode* head = root;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] != '.'){
                if (head -> next[word[i] - 'a'] == NULL) {
                    return false;
                }
                head = head -> next[word[i] - 'a'];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (head -> next[j] != NULL) {
                        bool isPresent = searchPartial(word.substr(i + 1, word.length() - i - 1), head -> next[j]);
                        if (isPresent) {
                            return true;
                        }
                    }
                }

                return false;
            }
        }
        return head -> endOfWord;
    }
    bool search(string word) {
        TrieNode* head = dict;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] != '.'){
                if (head -> next[word[i] - 'a'] == NULL) {
                    return false;
                }
                head = head -> next[word[i] - 'a'];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (head -> next[j] != NULL) {
                        bool isPresent = searchPartial(word.substr(i + 1, word.length() - i - 1), head -> next[j]);
                        if (isPresent) {
                            return true;
                        }
                    }
                }

                return false;
            }
        }

        return head -> endOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
