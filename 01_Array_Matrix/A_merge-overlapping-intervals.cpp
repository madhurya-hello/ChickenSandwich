// https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        
        int n = arr.size();
        
        // our answer array
        vector<vector<int>> ans;
        
        // first we will sort 
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            
            // before checking make sure, its not the last element, i != n-1
            if(i!=n-1 && arr[i][1] >= arr[i+1][0]){
                
                // storing the new range
                vector<int> temp;
                
                // pushing the starting index
                temp.push_back(arr[i][0]); 
                
                // initialising the ending index
                int endIndex = arr[i][1];

                // finding the ending index
                int x;
                for(x=i; x<n; x++){
                    // refreshing the end index
                    endIndex = arr[x][1] > endIndex ? arr[x][1] : endIndex ;
                    // before checking make sure, its not the last element, i != n-1
                    if(x!=n-1 && endIndex<arr[x+1][0]){
                        break;
                    }
                }
                
                // pushing the ending index
                temp.push_back(endIndex);
                
                // pushing into answer array
                ans.push_back(temp);
                
                // setting i=x because anyway i++ in the for-loop will take it to the (x+1)th index
                i = x;
            }
            else{
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
};
