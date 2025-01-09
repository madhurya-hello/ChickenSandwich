// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        
        // first we will count the number of 1s and convert them to 2s
        int ones = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==1){
                ones++;
                arr[i]=2;
            }
        }
        
        
        // Now we will simply sort the 0s and 2s
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            // ignoring the initial 0s and trailing 2s
            while(arr[i]==0 && i!=arr.size()-1){
                i++;
            }
            while(arr[j]==2 && j!=0){
                j--;
            }
            // swap
            if(i<j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        

        // converting back the 2s to 1s
        while(ones != 0){
            arr[i++]=1;
            ones--;
        }
        
    }
};

class Solution {
public:
    void sort012(vector<int>& arr) {

        // initialising the pointers 
        int low = 0; 
        int high = arr.size()-1;
        int mid = 0;

        // Dutch National Flag Algorithm
        while (mid <= high) {
            switch(arr[mid]) {
                case 0: 
                    swap(arr[low++], arr[mid++]); 
                    break;
                case 1: 
                    mid++;  
                    break;
                case 2: 
                    swap(arr[mid], arr[high--]);  
                    break;
            }
        }
    }
};