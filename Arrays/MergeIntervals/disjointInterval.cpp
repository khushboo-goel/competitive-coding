// https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/

class SummaryRanges {
  public:
    vector<int> Intervals;
    SummaryRanges() {
    }
    
    void addNum(int value) {
        Intervals.push_back(value);
        sort(Intervals.begin(), Intervals.end());
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        vector<int> tmp;
        int size = Intervals.size();

        if (size == 0) {
            return result;
        }

        tmp.push_back(Intervals[0]);
        int lastVal = Intervals[0];
        
        if (size == 1) {
            tmp.push_back(lastVal);
            result.push_back(tmp);
        }

        for (int i = 1; i < size; i++) {
            if (Intervals[i] == lastVal || Intervals[i] == lastVal + 1) {
                lastVal = Intervals[i];
            } else {
                tmp.push_back(lastVal);
                result.push_back(tmp);
                tmp = vector<int>(0);
                lastVal = Intervals[i];
                tmp.push_back(lastVal);
            }

            if (i == size - 1) {
                tmp.push_back(lastVal);
                result.push_back(tmp);
            }
        }

        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
