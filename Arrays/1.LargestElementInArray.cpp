// Largest element in array
/*
Your Task:  
You don't need to read input or print anything. Your task is to complete the function largest() which takes the array A[] 
and its size n as inputs and returns the maximum element in the array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/


#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largest(vector<int> &arr, int n){
    int max,i;
      max = arr[0];
      for(i=0; i<n; i++){
      if(arr[i]>max){
      max = arr[i];
      }
      }
      return max;

    }
};
