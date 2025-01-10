// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int row = matrixSize;
    int col = *matrixColSize;

    int targetRow = -1;
    int targetCol = -1;

    // checking the last element of every row
    for(int i=0; i<row; i++){
        if(target <= matrix[i][col-1]){
            targetRow=i;
            break;
        }
    }

    // element not found
    if(targetRow==-1){
        return 0;
    }
    
    // searching the element in that row
    for(int i=0; i<col; i++){
        if(matrix[targetRow][i] == target){
            targetCol=i;
            break;
        }
    }
    
    // element not found
    if(targetCol==-1){
        return 0;
    }

    return 1;
}