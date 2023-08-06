int Solution::books(vector<int> &A, int B) {
    // the sum of the pages becomes the search space here, hence binary search can be used
    int maxPages = INT_MIN;
    int noOfBooks = A.size();
    for (int i = 0; i < noOfBooks; i++){
        maxPages = (A[i] > maxPages) ? A[i]: maxPages;
    }
    
    // calculating sum since the book allocation becomes contigous
    vector<int> sum(noOfBooks, 0);
    sum[0] = A[0];
    for(int i = 1; i < noOfBooks; i++) {
        sum[i] = A[i] + sum[i - 1];
    }
    if (B == 1) {
        return sum[noOfBooks - 1];
    }
    if (B == noOfBooks) {
        return maxPages;
    }
    if (B > noOfBooks) {
        return -1;
    } 
    // search space is maxPages when noOfBooks = B
    // search space is sumOfpages when B = 1
    int left = maxPages;
    int right = sum[noOfBooks - 1];
    int minSum = sum[noOfBooks - 1];
    
    while(left <= right) {
        int mid = left + ((right - left) / 2);
        
        // start allocation and see if mid can be acheived as mid sum
        int breakPoints = 0;
        int lastBreakPoint = -1;
        int maxSumPages = INT_MIN;
        for (int i = 0; i < noOfBooks; i++) {
            int currSum = (breakPoints <= 0)? sum[i] : sum[i] - sum[lastBreakPoint];
            if (currSum > mid) {
                currSum -= A[i];
                breakPoints ++;
                lastBreakPoint = i - 1;
                maxSumPages = currSum > maxSumPages ? currSum : maxSumPages;
            }
            if (i == noOfBooks - 1) {
                maxSumPages = currSum > maxSumPages ? currSum : maxSumPages;
            }
        }

        if (breakPoints > B - 1) {
            left = mid + 1;
        } else {
            if (maxSumPages < minSum) {
                minSum = maxSumPages;
            }

            right = mid - 1;
        }
    }
    
    return minSum;
}

// https://www.interviewbit.com/problems/allocate-books/
// video link for understanding concepts : https://www.youtube.com/watch?v=OHUtHn-sdBc
