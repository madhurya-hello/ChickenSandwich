// https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        
        int maxSum=INT_MIN;
        int currSum=0;
        
        for (int i=0; i<arr.size(); i++){
            currSum = max(currSum+arr[i],arr[i]);
            maxSum = max(maxSum,currSum);
        }
        
        return maxSum;
        
    }
};

// Time Limit Exceeded
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        
        int max = INT_MIN;
        
        // changing the size of the sliding window
        for(int d=0; d<arr.size(); d++ ){
            // sliding the window
            for(int m=0, n=m+d; n<arr.size(); m++, n++){
                // calculating the sum
                int sum = 0;
                for(int i=m; i<=n; i++){
                    sum += arr[i];
                }
                if(sum>max){
                    max = sum;
                }
            }
        }
        
        return max;
        
    }
};