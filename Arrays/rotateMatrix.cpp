void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A[0].size();
    // first find transpose of the given matrix from right diagonal axis
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int tmp = A[i][j];
            A[i][j] = A[n - 1 - j][n - 1 - i];
            A[n - 1 - j][n - 1 - i] = tmp;
        }
    }
    
    // swap rows to finally get rotated matrix
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = A[i][j];
            A[i][j] = A[n - 1 - i][j];
            A[n - 1 - i][j] = tmp;
        }
    }
}

// https://www.interviewbit.com/problems/rotate-matrix/
