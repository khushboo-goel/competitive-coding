// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:
    int count = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        count++;
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        return (count % 2 == 0) ? (maxHeap.top() + (float)minHeap.top()) / 2 : maxHeap.top();
    }
};
