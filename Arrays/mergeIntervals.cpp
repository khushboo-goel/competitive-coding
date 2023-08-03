/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool isOverlapping(Interval i1, Interval newInterval) {
    bool endOverlap = i1.end > newInterval.start && i1.end < newInterval.end;
    bool startOverlap = i1.start < newInterval.end && i1.start > newInterval.start;
    bool allOverlap = i1.start > newInterval.start && i1.end < newInterval.end;
    
    return endOverlap || startOverlap || allOverlap;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int noOfIntervals = intervals.size();
    vector<Interval> result;
    
    if (noOfIntervals == 0) {
        result.push_back(newInterval);
        return result;
    }
    
    bool isInserted = false;
    for(int i = 0; i < noOfIntervals; i++){
        bool overlap = isOverlapping(intervals[i], newInterval);
        if (overlap) {
            int j = i;
            while(!isInserted && j < noOfIntervals && isOverlapping(intervals[j], newInterval)) {
                j++;
            }
            // actual last overlapping interval
            j --;
            int start = (intervals[i].start < newInterval.start) ? intervals[i].start : newInterval.start;
            int end = (intervals[j].end < newInterval.end) ? newInterval.end : intervals[j].end;
            Interval newInt = Interval(start, end);
            result.push_back(newInt);
            i = j;
            isInserted = true;
        } else {
            if (intervals[i].start > newInterval.end && !isInserted) {
                result.push_back(newInterval);
                isInserted = true;
            }
            result.push_back(intervals[i]);
        }
    }
    
    if (newInterval.start > intervals[noOfIntervals - 1].end && !isInserted){
        result.push_back(newInterval);
    }
    return result;
}

// https://www.interviewbit.com/problems/merge-intervals/
