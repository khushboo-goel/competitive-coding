class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int len = changed.size();
        vector<int> res;

        if (len % 2 != 0) {
            return res;
        }

        map<int, int> position;

        sort(changed.begin(), changed.end());
        for(int i = 0; i < len; i++) {
            if (position.find(changed[i]) == position.end()){
                position[changed[i]] = 1;
            } else {
                position[changed[i]]++;
            }
        }

        for (int i = 0; i < len; i++) {
            if (position[changed[i]] != 0){
                if (position[changed[i] * 2] != 0) {
                    position[changed[i]]--;
                    position[changed[i] * 2]--;
                    res.push_back(changed[i]);
                } else {
                    vector<int> blank;
                    return blank;
                }
            }
        }

        return res;
    }
};

// https://leetcode.com/problems/find-original-array-from-doubled-array/description/
