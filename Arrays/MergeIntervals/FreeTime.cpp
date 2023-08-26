// https://leetcode.com/problems/employee-free-time/description/

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int emp = schedule.size();

        vector<Interval> allSched;
        for(int i = 0; i < emp; i++) {
            for(int j = 0; j < schedule[i].size(); j++) {
                allSched.push_back(schedule[i][j]);
            }
        }

        sort(allSched.begin(), allSched.end(), compare);

        int len = allSched.size();
        Interval curr = allSched[0];
        vector<Interval> shortIntervals;
        for (int i = 1; i < len; i++) {
            // check if the next interval is overlapping to curr
            if (curr.end >= allSched[i].start) {
                curr.start = allSched[i].start < curr.start ? allSched[i].start : curr.start;
                curr.end = allSched[i].end > curr.end ? allSched[i].end : curr.end;
            } else {
                shortIntervals.push_back(curr);
                curr.start = allSched[i].start;
                curr.end = allSched[i].end;
            }
            if (i == len - 1) {
                shortIntervals.push_back(curr);
            }
        }

        vector<Interval> freeTime;
        for (int i = 1; i < shortIntervals.size(); i++) {
            Interval freeInt = Interval(shortIntervals[i - 1].end, shortIntervals[i].start);
            freeTime.push_back(freeInt);
        }

        return freeTime;
    }
};
