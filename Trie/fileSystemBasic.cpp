// https://leetcode.com/problems/design-file-system/
struct Trie {
    int value;
    bool endOfPath;
    map<string, Trie*> next;
    Trie() {}
    Trie(int val, bool isEnd) {
        value = val;
        endOfPath = isEnd;
    }
};

class FileSystem {
private:
    Trie* fs;

    vector<string> parsePath(string path) {
        string s = "";
        vector<string> parsedPath;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (s != "") {
                    parsedPath.push_back(s);
                    s = "";
                }
            } else {
                s += path[i];
            }
        }
        if (s != "") {
            parsedPath.push_back(s);
        }
        return parsedPath;
    }
public:
    FileSystem() {
        fs = new Trie();
    }
    
    bool createPath(string path, int value) {
        vector<string> processedPath = parsePath(path);
        int len = processedPath.size();
        Trie* tmp = fs;
        bool isPresent = true;

        for (int i = 0 ; i < len; i++) {
            if (i == len - 1) {
                if ((tmp -> next).find(processedPath[i]) == (tmp -> next).end()) {
                    Trie* newNode = new Trie(value, true);
                    (tmp -> next)[processedPath[i]] = newNode;
                    isPresent = false;
                }
            } else {
                if ((tmp -> next).find(processedPath[i]) == (tmp -> next).end()) {
                    return false;
                }
            }
            tmp = (tmp -> next)[processedPath[i]];
        }


        return !isPresent;
    }
    
    int get(string path) {
        vector<string> processedPath = parsePath(path);
        int len = processedPath.size();
        Trie* tmp = fs;

        for (int i = 0; i < len; i++) {
            if ((tmp -> next).find(processedPath[i]) == (tmp -> next).end()) {
                return -1;
            }
            tmp = (tmp -> next)[processedPath[i]];
        }

        return tmp -> value;
    }
};
