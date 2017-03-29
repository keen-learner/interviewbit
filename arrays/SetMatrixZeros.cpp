/*
Set Matrix Zeros
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1


LEETCODE: # 73: https://leetcode.com/problems/set-matrix-zeroes/#/description

*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    if (A.empty()) return;
    const auto m = A.size(); // m =  # of rows
    const auto n = A[0].size(); // n = # of columns
    bool row = false;
    bool col = false;
    for (int j = 0; j<n ; ++j ) {
        if (A[0][j] == 0) {row = true; break;}
    }
    for (int i = 0; i<m ; ++i ) {
        if (A[i][0]== 0) {col = true; break;}
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j ) {
            if (A[i][j] == 0) {
                A[i][0] = 0; // set ith row
                A[0][j] = 0; // set jth column
            }
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j ) {
            if (A[i][0] == 0 || A[0][j]==0) A[i][j] = 0;    
        }
    }
    if(row) {
        for(int j = 0; j<n ; ++j) A[0][j] = 0;
    }
    if(col) {
        for (int i = 0; i<m ; ++i ) A[i][0] = 0;
    }
    
	/*if(matrix.empty()) return ;
	int rowSize = matrix.size(), colSize = matrix[0].size();
	bool firstRow = false, firstCol = false;
	for(int j = 0; j < colSize; ++j) if(matrix[0][j] == 0) firstRow = true;
	for(int i = 0; i < rowSize; ++i) if(matrix[i][0] == 0) firstCol = true;
	for(int i = 1; i < rowSize; ++i)
	    for(int j = 1; j < colSize; ++j)
		if(matrix[i][j] == 0) matrix[0][j] = matrix[i][0] = 0;
	for(int i = 1; i < rowSize; ++i)
	    for(int j = 1; j < colSize; ++j)
		if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j] = 0;

	if(firstRow) for(int j = 0; j < colSize; ++j) matrix[0][j] = 0;
	if(firstCol) for(int i = 0; i < rowSize; ++i) matrix[i][0] = 0;
	*/
}

/*

// official

class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            int rownum = matrix.size();
            if (rownum == 0)  return;
            int colnum = matrix[0].size();
            if (colnum == 0)  return;

            bool hasZeroFirstRow = false, hasZeroFirstColumn = false;

            // Does first row have zero?
            for (int j = 0; j < colnum; ++j) {
                if (matrix[0][j] == 0) {
                    hasZeroFirstRow = true;
                    break;
                }
            }

            // Does first column have zero?
            for (int i = 0; i < rownum; ++i) {
                if (matrix[i][0] == 0) {
                    hasZeroFirstColumn = true;
                    break;
                }
            }

            // find zeroes and store the info in first row and column
            for (int i = 1; i < rownum; ++i) {
                for (int j = 1; j < colnum; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            // set zeroes except the first row and column
            for (int i = 1; i < rownum; ++i) {
                for (int j = 1; j < colnum; ++j) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
                }
            }

            // set zeroes for first row and column if needed
            if (hasZeroFirstRow) {
                for (int j = 0; j < colnum; ++j) {
                    matrix[0][j] = 0;
                }
            }
            if (hasZeroFirstColumn) {
                for (int i = 0; i < rownum; ++i) {
                    matrix[i][0] = 0;
                }
            }
        }
};

*/
