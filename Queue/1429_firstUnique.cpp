// https://leetcode.com/problems/first-unique-number/
class FirstUnique {
public:
    unordered_map<int, int> count;
    queue<int> uniques;
    FirstUnique(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
            uniques.push(nums[i]);
        }
    }
    int showFirstUnique() {
        while(count[uniques.front()] > 1) {
            uniques.pop();
        }
        return uniques.size() > 0 ? uniques.front() : -1;
    }
    
    void add(int value) {
        count[value]++;
        uniques.push(value);
    }
};
