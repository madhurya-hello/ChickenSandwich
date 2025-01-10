// https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    
    int row = mat.size();
    int col = mat[0].size();
    
    // this will follow the diagonal path
    int leftLimit = 0;
    
    // Step 01 - we will take the transpose of the matrix
    
    for(int i=0; i<row; i++){
        
        // traversing every row from right to left
        for (int j=col-1; j>=leftLimit; j--){
            swap( mat[i][j] , mat[j][i] );
        }
        
        // following the diagonal path
        leftLimit++;
        
        // check
        if(leftLimit>=col-1){
            break;
        }
    }
    
    // Step 02 - we will rotate every row
    
    for(int i=0; i<row; i++){
        // rotating the row
        for(int x=0,y=col-1; x<=y; x++, y--){
            swap( mat[i][x] , mat[i][y] );
        }
    }
}