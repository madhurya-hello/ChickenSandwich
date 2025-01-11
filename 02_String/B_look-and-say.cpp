// https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        
        // two base cases
        if(n==1){
            string a = "1";
            return a;
        }
        if(n==2){
            string a = "11";
            return a;
        }
        
        // recursive call
        string temp = lookandsay(n-1);
        
        // we will analyze the temp and store it here
        string ans = "";
        
        // important variables
        int counter=1;
        int i;
        
        // analyzing temp...
        for(i=0; i<temp.size()-1; i++){
            if(temp[i]==temp[i+1]){
                counter++;
            }
            else{
                ans.push_back(counter+48);  // 48 added to convert integer to string
                ans.push_back(temp[i]);
                counter=1;
            }
        }
        
        // pushing the last element of temp;
        ans.push_back(counter+48);
        ans.push_back(temp[i]);
        
        
        return ans;
    }   
};