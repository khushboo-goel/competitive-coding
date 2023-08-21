bool compare(vector<int> &a, vector<int> &b) {
    return (a[0] == b[0]) ? a[1] < b[1] : a[0] > b[0];
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int len = properties.size();
        sort(properties.begin(), properties.end(), compare);

        int maxDef = INT_MIN;
        int weak = 0;
        for(int i = 0; i < len; i++) {
            if (properties[i][1] < maxDef) {
                weak ++;
            } else {
                maxDef = properties[i][1];
            }
        }
        return weak;
    }
};

// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/
