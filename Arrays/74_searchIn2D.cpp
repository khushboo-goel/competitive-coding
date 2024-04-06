// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=list&envId=pcxjbubg

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    // // one binary seach to find the row;
    // int top = 0;
    // int bottom = m - 1;
    // int row;
    // while(top <= bottom) {
    //     int mid = (top + bottom) / 2;

    //     if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
    //         row = mid;
    //         break;
    //     } else if (target < matrix[mid][0]) {
    //         bottom = mid - 1;
    //     } else {
    //         top = mid + 1;
    //     }
    // }

    // int left = 0;
    // int right = n - 1;
    // while(left <= right) {
    //     int mid = (left + right) / 2;

    //     if (target == matrix[row][mid]) {
    //         return true;
    //     } else if (target < matrix[row][mid]) {
    //         right = mid - 1;
    //     } else {
    //         left = mid + 1;
    //     }
    // }

    // return false;

    // consider it as a list of m * n elements

    int left = 0;
    int right = n * m - 1;
    while(left <= right) {
        int mid = (left + right) / 2;

        int row = mid / n;
        int col = mid % n;

        if (target == matrix[row][col]) {
            return true;
        } else if (target < matrix[row][col]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}
