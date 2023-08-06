int Solution::solve(vector<int> &A, int B) {
    int len = A.size();
    int left = 0;
    int right = len - 1;
    
    int bitonicPoint = -1;
    // find bitonic point
    while(left <= right) {
        int mid = left + ((right - left)/2);
        if (mid != 0 && mid != len - 1 && A[mid] > A[mid -1] && A[mid] > A[mid + 1]) {
            bitonicPoint = mid;
            break;
        } else if (mid == 0 || A[mid] < A[mid + 1]) {
            left = mid + 1;
        } else if (mid == len - 1 || A[mid] < A[mid - 1]){
            right = mid - 1;
        }
    }
    
    if (A[bitonicPoint] == B) {
        return bitonicPoint;
    }
    
    left = 0;
    right = bitonicPoint - 1;
    //binary search on left part
    while(left <= right) {
        int mid = left + ((right - left) / 2);
        
        if (A[mid] == B) {
            return mid;
        } else if (A[mid] > B) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    left = bitonicPoint + 1;
    right = len - 1;
    //binary search on right part
    while(left <= right) {
        int mid = left + ((right - left) / 2);
        
        if (A[mid] == B) {
            return mid;
        } else if (A[mid] > B) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

// https://www.interviewbit.com/problems/search-in-bitonic-array/
