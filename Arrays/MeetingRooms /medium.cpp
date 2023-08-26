bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

struct sortQueue{
    bool operator()(int a, int b) {
        return a > b;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len == 0) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<int, vector<int>, sortQueue> dq;
        dq.push(0);
        
        for (int i = 0; i < len; i++) {
            int vacantTime = dq.top();
            if (vacantTime <= intervals[i][0]){
                dq.pop();
            }
            dq.push(intervals[i][1]);
        }

        return dq.size();
    }
};

// https://leetcode.com/problems/meeting-rooms-ii/description/
