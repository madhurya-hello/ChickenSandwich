// https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
                
        sort(nums.begin(), nums.end());
        
        int start = 0;
        int end = n-1;
        int mid = start + ((end-start)/2);

        while(true){
            if(nums[mid] != mid){
                
            }
        }
    }
};