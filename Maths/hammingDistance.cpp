int Solution::hammingDistance(const vector<int> &A) {
    int len = A.size();
    if (len == 0 || len == 1) {
        return 0;
    }
    long long maskVal = 1;
    int bit = 0;
    long long hammingDist = 0;

    long long maxVal = INT_MIN;
    
    for(int i = 0; i < len; i++){
        maxVal = A[i] > maxVal ? A[i] : maxVal;
    }

    while(maxVal > 0){
        long long zeroes = 0;
        long long ones = 0;
        for (int i = 0; i < len; i++) {
            long long val = (A[i] & maskVal) >> bit;
            ones = (val == 1) ? ones + 1 : ones;
            zeroes = (val == 0) ? zeroes + 1 : zeroes;
        }
        hammingDist = (hammingDist + (2 * zeroes * ones) % 1000000007) % 1000000007;
        maskVal = maskVal << 1;
        maxVal = maxVal >> 1;
        bit ++;
    }
    
    return hammingDist;
}

// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
