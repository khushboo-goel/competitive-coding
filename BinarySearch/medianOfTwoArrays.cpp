// Good video to learn : https://www.youtube.com/watch?v=yD7wV8SyPrc
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if (n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int start = 0;
    int end = n1;

    while(start <= end) {
        int mid1 = start + (end - start) / 2;
        int mid2 = ((n1 + n2) / 2) - mid1;
        int l1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
        int r1 = mid1 == n1 ? INT_MAX : nums1[mid1];
        int l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
        int r2 = mid2 == n2 ? INT_MAX : nums2[mid2];

        if (l1 > r2) {
            end = mid1 - 1;
        } else if (l2 > r1) {
            start = mid1 + 1;
        } else {
            if ((n1 + n2) % 2 == 0){
                return ((double)(max(l1, l2) + min(r1, r2) ) / 2);
            } else {
                return (double)(min(r1, r2));
            }
        }
    }

    return 0.0;
}
