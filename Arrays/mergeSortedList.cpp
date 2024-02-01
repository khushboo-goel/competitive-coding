void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A.size() == 0) {
        for (int i = 0; i < B.size(); i++) {
            A.push_back(B[i]);
        }
        return;
    }
    
    if (B.size() == 0){
        return;
    }
    int lenB = B.size();
    int lenA = A.size();
    int i = 0, j = 0;
    // n^ 2 approach because insert will cause shifting in elements in vector
    // while(i < lenA && j < lenB) {
    //     if (A[i] > B[j]){
    //         A.insert(A.begin() + i, B[j]);
    //         i++;
    //         j++;
    //         lenA++;
    //     } else {
    //         i++;
    //     }
    // }
    
    // while (j < B.size()) {
    //     A.push_back(B[j]);
    //     j++;
    // }
    
    for(; j < lenB; j++){
        A.push_back(B[j]);
    }
    
    sort(A.begin(), A.end());
    
    return;
}

// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/




/* -------------------------------------------------------------------------------------------------------------------------------------------------------- */
/* SIMILAR QUESTION WITH MORE OPTIMISED SOLUTION */
// https://leetcode.com/problems/merge-sorted-array/description/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // three pointer technique
        int x = m - 1;
        int y = m + n - 1;
        int z = n - 1;

        if (m == 0) {
            nums1 = nums2;
        }
        while(z >= 0 && x >= 0) {
            // last of larger array is less than smaller array
            if (nums1[x] < nums2[z]) {
                nums1[y] = nums2[z];
                y--;
                z--;
            } else {
                nums1[y] = nums1[x];
                y--;
                x--;
            }
        }

        if (z >= 0) {
            while(z >= 0) {
                nums1[y] = nums2[z];
                y--;
                z--;
            }
        }
    }
