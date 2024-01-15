// https://leetcode.com/problems/lru-cache/

struct DLL {
    int key;
    int value;
    DLL* next;
    DLL* prev;
    DLL(int k, int val) {
        key = k;
        value = val;
        next = NULL;
        prev = NULL;
    } 
};

class LRUCache {
public:
    map<int, DLL*> cache;
    DLL* head; // head of the DLL which stores values
    int size = 0;
    int currSize = 0;
    LRUCache(int capacity) {
        size = capacity;
        head = NULL;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end() && cache[key] != NULL) {
            if (head != cache[key]) { // means it is not already in the front of the DLL
                DLL* node = cache[key];
                node -> prev -> next = node -> next;
                if (node -> next != NULL) {
                    node -> next -> prev = node -> prev;
                }
                node -> prev = NULL;
                node -> next = head;
                head -> prev = node;
                head = node;
            }
            return cache[key] -> value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end() && cache[key] != NULL) {
            cache[key] -> value = value;

            //again using logic for LRU
            if (head != cache[key]) { // means it is not already in the front of the DLL
                DLL* node = cache[key];
                node -> prev -> next = node -> next;
                if (node -> next != NULL) {
                    node -> next -> prev = node -> prev;
                }
                node -> prev = NULL;
                node -> next = head;
                head -> prev = node;
                head = node;
            } 
        } else {
            if (currSize < size) {
                DLL* newNode = new DLL(key, value);
                cache[key] = newNode;

                if (head == NULL) {
                    head = newNode;
                }
                else {
                    newNode -> next = head;
                    head -> prev = newNode;
                    head = newNode;
                }
                currSize ++;
            } else {
                DLL* temp = head;
                while(temp -> next != NULL) {
                    temp = temp -> next;
                }

                int oldKey = temp -> key;
                temp -> key = key;
                temp -> value = value;
                if (head != temp) { // means it is not already in the front of the DLL
                    DLL* node = temp;
                    node -> prev -> next = node -> next;
                    if (node -> next != NULL) {
                        node -> next -> prev = node -> prev;
                    }
                    node -> prev = NULL;
                    node -> next = head;
                    head -> prev = node;
                    head = node;
                }

                cache[oldKey] = NULL;
                cache[key] = temp;
            }
        }
    }
};
