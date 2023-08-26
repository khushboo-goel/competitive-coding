/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// Ascending order
bool compare(Interval A, Interval B) {
    return A.start < B.start;
}
bool isOverlap(Interval A, Interval B) {
    return B.start <= A.end;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), compare);
    
    int len = A.size();
    if (len == 0 || len == 1) {
        return A;
    }
    vector<Interval> result;
    Interval overlap;
    overlap.start = A[0].start;
    overlap.end = A[0].end;
    
    for (int i = 1; i < len; i++) {
        bool olap = isOverlap(overlap, A[i]);
        if (olap) {
            overlap.start = (overlap.start < A[i].start) ? overlap.start: A[i].start;
            overlap.end = (overlap.end < A[i].end) ? A[i].end: overlap.end;
        } else {
            result.push_back(overlap);
            overlap.start = A[i].start;
            overlap.end = A[i].end;
        }
        
        if (i == len - 1) {
            result.push_back(overlap);
        }
    }
    
    return result;
}

// https://www.interviewbit.com/problems/merge-overlapping-intervals/
