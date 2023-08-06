int Solution::search(const vector<int> &A, int B) { 
    int len = A.size();   
    int left = 0;
    int right = len - 1;
    
    while(left <= right) {
        int mid = left + ((right - left) / 2);
        
        if (A[mid] == B) {
            return mid;
        }
        // find if mid is before or after pivot element
        bool beforePivot = (A[mid] > A[left]);
        bool afterPivot = (A[mid] < A[right]);
        if ((beforePivot && A[mid] > B && A[left] <= B)
        || (afterPivot && !(A[mid] < B && A[right] >=B))) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return -1;
}

// https://www.interviewbit.com/problems/rotated-sorted-array-search/

// NOTE: Dont make the solution complicated. The solution if condition depends on where the mid lies and that will help reach to solution faster.
