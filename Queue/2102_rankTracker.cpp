// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/

class sortMaxHeap{
public:
    bool operator()(pair<string, int> a, pair<string, int> b) {
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    }
};

class sortMinHeap{
public:
    bool operator()(pair<string, int> a, pair<string, int> b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};

class SORTracker {
private:
    int query;
public:
    priority_queue<pair<string, int>, vector<pair<string, int>>, sortMaxHeap> maxHeap;
    priority_queue<pair<string, int>, vector<pair<string, int>>, sortMinHeap> minHeap;
    SORTracker() {
        query = 0;
    }
    
    void add(string name, int score) {
        maxHeap.push(make_pair(name, score));
    }
    
    string get() {
        query++;
        while(minHeap.size() < query) {
            pair<string, int> val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val) ;
        }
        while(!maxHeap.empty() && (maxHeap.top().second > minHeap.top().second || (maxHeap.top().second == minHeap.top().second && maxHeap.top().first < minHeap.top().first))) {
            pair<string, int> val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
            val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }
        return minHeap.top().first;
    }
};
