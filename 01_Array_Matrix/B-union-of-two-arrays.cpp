// https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1

// real challenge is to do this without using any STL functions

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        
        // sorting the arrays
        stable_sort(a.begin(), a.end());
        stable_sort(b.begin(), b.end());
        
        // two pointers for each array
        int i=0;
        int j=0;
        
        // respective pointer will go down if a pointer reaches the end of an array
        int flagA=0;
        int flagB=0;
        
        // counter for unique elements
        int count = 0;
        
        while (flagA==0 && flagB==0 && i<a.size() && j<b.size()) {
            
            // Note-01: 
            // we move the pointers to the next unique element in each case
            // e.g. [1,1,1,1,2,2,2,4,4,5,5,5]
            // if the pointer is pointing at index 4, then now it will point at index 7 and increase the count by one
            // also, if the pointer is pointing at index 9, then it will turn down the flagA and increase the count by one
            
            // Note-02:
            // also notice that if any of the flag is turned down at any instance, it will ignore the main code and reach the flag-handlers at the end
            // hence, in every loop we check the flags first
            
            // if a[i]==b[j] then we will move both the pointers to the next unique element in each array and increase the count by one
            if(flagA==0 && flagB==0 && a[i] == b[j]){
                count++;
                int temp = a[i];
                while(flagA==0 && a[i]==temp){
                    i++;
                    if(i==a.size())
                        flagA=1;
                }
                while(flagB==0 && b[j]==temp){
                    j++;
                    if(j==b.size())
                        flagB=1;
                }
            }
            
            // if a[i] < b[j] then we move the pointer of 'a' to the next unique element and increase the count by one
            if(flagA==0 && flagB==0 && a[i] < b[j]){
                count++;
                int temp = a[i];
                while(flagA==0 && flagB==0 && a[i]==temp){
                    i++;
                    if(i==a.size())
                        flagA=1;
                }
            }
            
            // if a[i] > b[j] then we move the pointer of 'b' to the next unique element and increase the count by one
            if(flagA==0 && flagB==0 && a[i] > b[j]){
                count++;
                int temp = b[j];
                while(flagA==0 && flagB==0 && b[j]==temp){
                    j++;
                    if(j==b.size())
                        flagB=1;
                }
            }
        }
        
        
        // FLAG HANDLERS
        
        if(flagA==1 && flagB==0){
            while(flagB==0){    
                count++;
                int temp = b[j];
                while(flagB==0 && b[j]==temp){
                    j++;
                    if(j==b.size())
                        flagB=1;
                }
            }
        }
        
        if(flagB==1 && flagA==0){
            while(flagA==0){    
                count++;
                int temp = a[i];
                while(a[i]==temp && flagA==0){
                    i++;
                    if(i==a.size())
                        flagA=1;
                }
            }
        }
        
        
        return count;
    }
};