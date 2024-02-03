// https://leetcode.com/problems/minimum-health-to-beat-game/

long long minimumHealth(vector<int>& damage, int armor) {
    int n = damage.size();

    // find max and sum together 
    long long sum = 0;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += (long long)damage[i];
        maxVal = max(maxVal, damage[i]);
    }

    int protectionPossible = min(armor, maxVal);

    return sum + 1 - (long long)protectionPossible;
}
