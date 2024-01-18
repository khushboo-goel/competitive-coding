// https://leetcode.com/problems/h-index-ii/

int hIndex(vector<int>& citations) {
    int size = citations.size();

    int left = 0;
    int right = size - 1;
    int hIndex = 0;

    while(left <= right) {
        int mid = (left + right) / 2;
        hIndex = max(hIndex, min(citations[mid], size - mid));

        if (size - mid >= citations[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

    }

    return hIndex;
}
