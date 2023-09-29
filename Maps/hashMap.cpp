// https://leetcode.com/problems/design-hashmap/
class MyHashMap {
public:
    vector<pair<int, int>> hashMap;
    MyHashMap() {
        hashMap = vector<pair<int, int>>(0);
    }
    
    void put(int key, int value) {
        bool isFound = false;
        for (int i = 0; i < hashMap.size(); i++) {
            if (hashMap[i].first == key) {
                hashMap[i].second = value;
                isFound = true;
                break;
            }
        }

        if (!isFound) {
            hashMap.push_back(make_pair(key, value));
        }
    }
    
    int get(int key) {
        for (int i = 0; i < hashMap.size(); i++) {
            if (hashMap[i].first == key) {
                return hashMap[i].second;
            }
        } 
        return -1;
    }
    
    void remove(int key) {
        for (int i = 0; i < hashMap.size(); i++) {
            if (hashMap[i].first == key) {
                vector<pair<int, int>> :: iterator itr = hashMap.begin() + i;
                hashMap.erase(itr);
            }
        }
    }
};
