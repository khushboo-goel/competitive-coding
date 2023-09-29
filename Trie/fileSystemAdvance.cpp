// https://leetcode.com/problems/design-in-memory-file-system/
// NOTE: Nothing too complicated, even though a hard question. Jsut stick to requirements and that should do.
struct Trie {
    map<string, string> files;
    map<string, Trie*> folders;
};
class FileSystem {
private:
    Trie* fileSystem;
    vector<string> parsedPath(string path) {
        string s = "";
        int len = path.length();
        vector<string> parsedPath(0);

        for(int i = 0; i < len; i++) {
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
        fileSystem = new Trie();
    }
    
    vector<string> ls(string path) {
        vector<string> processedPath = parsedPath(path);
        int len = processedPath.size();
        vector<string> list;
        Trie* Dir = fileSystem;

        for (int i = 0; i < len - 1; i++) {
            if ((Dir -> folders).find(processedPath[i]) == (Dir -> folders).end()) {
                return list;
            } else {
                Dir =  (Dir -> folders)[processedPath[i]];
            }
        }


        if (len > 0 && (Dir -> files).find(processedPath[len - 1]) != (Dir -> files).end()){
            list.push_back(processedPath[len - 1]);
        } else {
            Dir = (len == 0) ? fileSystem :(Dir -> folders)[processedPath[len - 1]];
            map<string, string> :: iterator fileItr = (Dir -> files).begin();
            for (; fileItr != (Dir -> files).end(); fileItr++) {
                list.push_back(fileItr -> first);
            }

            map<string, Trie*> :: iterator folderItr = (Dir -> folders).begin();
            for (; folderItr != (Dir -> folders).end(); folderItr++) {
                list.push_back(folderItr -> first);
            }
        }
        
        sort(list.begin(), list.end());
        return list;
    }
    
    void mkdir(string path) {
        vector<string> processedPath = parsedPath(path);
        Trie* Dir = fileSystem;
        for (int i = 0; i < processedPath.size(); i++) {
            if ((Dir -> folders).find(processedPath[i]) == (Dir -> folders).end()) {
                Trie* newNode = new Trie();
                (Dir -> folders)[processedPath[i]] = newNode;
            }
            Dir =  (Dir -> folders)[processedPath[i]];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> processedPath = parsedPath(filePath);
        Trie* Dir = fileSystem;
        for (int i = 0; i < processedPath.size() - 1; i++) {
            if ((Dir -> folders).find(processedPath[i]) == (Dir -> folders).end()) {
                Trie* newNode = new Trie();
                (Dir -> folders)[processedPath[i]] = newNode;
            }
            Dir =  (Dir -> folders)[processedPath[i]];
        }

        (Dir -> files)[processedPath[processedPath.size() - 1]] += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> processedPath = parsedPath(filePath);
        Trie* Dir = fileSystem;
        for (int i = 0; i < processedPath.size() - 1; i++) {
            if ((Dir -> folders).find(processedPath[i]) == (Dir -> folders).end()) {
                return "";
            }
            Dir =  (Dir -> folders)[processedPath[i]];
        }

        return (Dir -> files)[processedPath[processedPath.size() - 1]];
    }
};
