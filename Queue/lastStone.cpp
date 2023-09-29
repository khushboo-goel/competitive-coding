// https://leetcode.com/problems/last-stone-weight/

struct sortQueue {
    bool operator()(int &a, int &b) {
        return a < b;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int, vector<int>, sortQueue> dq;
        for (int i = 0; i < n; i++) {
            dq.push(stones[i]);
        }
        while(dq.size() > 1) {
            int first = dq.top();
            dq.pop();
            int second = dq.top();
            dq.pop();

            if (first != second) {
                dq.push(abs(first - second));
            }
        }

        return dq.size() == 0 ? 0 : dq.top();
    }
};
