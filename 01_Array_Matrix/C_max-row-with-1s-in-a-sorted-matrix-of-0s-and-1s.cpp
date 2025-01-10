// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        
        int row = arr.size();
        int col = arr[0].size();
        int ans;
        
        int oneIndex = col;
        
        for (int i=0; i<row; i++){
            // we only update the 'ans' iff a row contains more no of 1s than the current 'ans' row
            if(arr[i][oneIndex-1] == 1){
                ans = i;
                // setting the oneIndex
                while(arr[i][oneIndex-1] == 1){
                    oneIndex--;
                    // check
                    if(oneIndex==0){
                        return i;
                    }
                }
            }
        }
        
        if(oneIndex == col){
            return -1;
        }
        
        return ans;
    }
};