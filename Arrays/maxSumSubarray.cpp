vector<int> Solution::maxset(vector<int> &A) {
    int len = A.size();
    int start = 0, currStart = 0, currLen = 0, maxLen = INT_MIN;
    long long currSum = 0, maxSum = INT_MIN;
    
    for (int i = 0; i < len; i++){
        if (A[i] >= 0) {
            currSum += A[i];
            currLen ++;
            
            // last element
            if (i == len - 1) {
                if (currSum > maxSum || (currSum == maxSum && currLen > maxLen)) {
                    maxLen = currLen;
                    maxSum = currSum;
                    start = currStart;
                }
            }
        } else {
            if (currSum > maxSum || (currSum == maxSum && currLen > maxLen)) {
                maxLen = currLen;
                maxSum = currSum;
                start = currStart;
            }
            currLen = 0;
            currSum = 0;
            currStart = i + 1;
        }
    }
    
    vector<int> result;
    for(int i = start; i < start + maxLen; i++) {
        result.push_back(A[i]);
    }
    return result;
}

// https://www.interviewbit.com/problems/max-non-negative-subarray/
