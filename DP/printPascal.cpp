vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    vector<int> firstRow(1, 1);
    vector<int> secondRow(2, 1);
    
    triangle.push_back(firstRow);
    if (numRows == 1) {
        return triangle;
    }
    triangle.push_back(secondRow);
    if (numRows == 2){
        return triangle;
    }

    for (int i = 3; i <= numRows; i++) {
        vector<int> row(i, 1);
        for(int j = 1; j < i - 1; j++){
            row[j] = triangle[i - 2][j-1] + triangle[i - 2][j]; 
        }
        triangle.push_back(row);
    }

    return triangle;
}

// https://leetcode.com/problems/pascals-triangle/description/
