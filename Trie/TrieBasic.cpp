// https://leetcode.com/problems/implement-trie-prefix-tree/
struct trieNode {
    vector<trieNode*> next;
    bool isEnd;
    trieNode() {
        next = vector<trieNode*> (26, NULL);
        isEnd = false;
    }
};

class Trie {
public:
    trieNode* dict;
    Trie() {
        dict = new trieNode();
    }
    
    void insert(string word) {
        int len = word.length();
        // This us the major struggling point in this question. What should be used for recursive call ? (Entire node or vector)
        trieNode* root = dict;

        for (int i = 0; i < len; i++) {
            if (root -> next[word[i] - 'a'] == NULL) {
                trieNode* newNode = new trieNode();
                root -> next[word[i] - 'a'] = newNode;
            }
            if (i == len - 1) {
                root -> next[word[i] - 'a'] -> isEnd = true;
            }
            root = root -> next[word[i] - 'a'];
        }
    }
    
    bool search(string word) {
        int len = word.length();
        vector<trieNode*> next = dict -> next;

        for (int i = 0; i < len; i++) {
            if (next[word[i] - 'a'] == NULL) {
                return false;
            } else if (i == len - 1 && next[word[i] - 'a'] -> isEnd == true) {
                return true;
            } else {
                next = next[word[i] - 'a'] -> next;
            }
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        int len = prefix.size();
        vector<trieNode*> next = dict -> next;

        for (int i = 0; i < len; i++) {
            if (next[prefix[i] - 'a'] == NULL) {
                return false;
            }
            next = next[prefix[i] - 'a'] -> next;
        }

        return true;
    }
};
