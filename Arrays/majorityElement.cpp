int Solution::majorityElement(const vector<int> &A) {
    int len = A.size();
    int majCount = len / 2;
    map<int, int> values;
    
    for (int i = 0; i < len; i++){
        if (values.find(A[i]) == values.end()){
            values[A[i]] = 1;
        } else {
            values[A[i]] += 1;
        }
    }
    
    for(map<int, int>:: iterator itr = values.begin(); itr != values.end(); itr++) {
        if (itr -> second > majCount) {
            return itr -> first;
        }
    }
    
    return -1;
}

// https://www.interviewbit.com/problems/majority-element/
