bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);  

        if (intervals.size() == 0) {
            return true;
        }
        int freeTime = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < freeTime) {
                return false;
            } else {
                freeTime = intervals[i][1];
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/meeting-rooms/description/
