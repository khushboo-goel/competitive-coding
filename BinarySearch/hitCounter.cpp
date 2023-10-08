// https://leetcode.com/problems/design-hit-counter/
class HitCounter {
public:
    vector<int> hitList;
    int diff = 300;
    HitCounter() {
        hitList = vector<int>(0);
    }
    
    void hit(int timestamp) {
        hitList.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int len = hitList.size();
        int index = len;

        int start = 0;
        int end = len - 1;

        while(start <= end) {
            int mid = start + ((end - start) / 2);

            if (timestamp - hitList[mid] < diff) {
                index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return len - index;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
