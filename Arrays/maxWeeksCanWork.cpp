// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/description/

long long numberOfWeeks(vector<int>& milestones) {
    vector<int> tmp(milestones.begin(), milestones.end());
    sort(tmp.begin(), tmp.end(), greater<int>());

    int tasks = 0;
    for (int i = 1; i < tmp.size(); i++) {
        tasks += tmp[i];
    }

    if (abs(tmp[0] - tasks) > 1) {
        return 2 * tasks + 1;
    } else {
        return tmp[0] + tasks;
    }
}
