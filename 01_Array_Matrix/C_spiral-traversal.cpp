// https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        
        vector<int> ans;
        
        int row = mat.size();
        int col = mat[0].size();
        
        int left = 0;
        int right = col-1;
        int top = 0;
        int bottom = row-1;
        
        while(left<=right && top<=bottom){
            
            // top row
            for(int i=left; i<=right; i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            if(top>bottom){break;}  // check
            
            // right column
            for(int i=top; i<=bottom; i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(right<left){break;}  // check
            
            // bottom row
            for(int i=right; i>=left; i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
            if(bottom<top){break;}  // check
            
            // leftmost column
            for(int i=bottom; i>=top; i--){
                ans.push_back(mat[i][left]);
            }
            left++;
        }
        
        return ans;
    }
};