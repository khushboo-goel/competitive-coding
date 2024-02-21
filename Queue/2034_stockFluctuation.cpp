// https://leetcode.com/problems/stock-price-fluctuation/
class sortMax {
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
};

class sortMin {
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.second > b.second;
    }
};
class StockPrice {
public:
  unordered_map<int, int> updates;
  priority_queue<pair<int, int>, vector<pair<int, int>>, sortMax> maxHeap;
  priority_queue<pair<int, int>, vector<pair<int, int>>, sortMin> minHeap;
  int latestTimestamp;

  StockPrice() {
      latestTimestamp = 0;
  }
  
  void update(int timestamp, int price) {
      maxHeap.push(make_pair(timestamp, price));
      minHeap.push(make_pair(timestamp, price));
      updates[timestamp] = price;
      if (timestamp > latestTimestamp) {
          latestTimestamp = timestamp;
      }

      // update maxHeap
      while(!maxHeap.empty() && maxHeap.top().second != updates[maxHeap.top().first]) {
          maxHeap.pop();
      }

      // update minHeap
      while(!minHeap.empty() && minHeap.top().second != updates[minHeap.top().first]) {
          minHeap.pop();
      }

  }
  
  int current() {
      return updates[latestTimestamp];
  }
  
  int maximum() {
      return maxHeap.top().second;
  }
  
  int minimum() {
      return minHeap.top().second;
  }
};
