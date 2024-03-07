// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int, int> count;

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    vector<int> vals;
    for (unordered_map<int, int>:: iterator itr = count.begin(); itr != count.end(); itr++) {
        vals.push_back(itr -> second);
    }

    sort(vals.begin(), vals.end());

    int removals = k;
    int i = 0;
    while(i < vals.size() && removals > 0) {
        if (vals[i] > removals) {
            removals = 0;
        } else {
            removals -= vals[i];
            i++;
        }
    }

    return vals.size() - i;
}
