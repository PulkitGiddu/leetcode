Q - Next Smaller Element
Code: 
#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s; 
    s.push(-1);
  // new vector mae ans store kr lo and return kr do   
  vector<int> ans(n);
    
    for(int i = n -1; i >=0; i-- ){
        int curr = arr[i];
      
      //check for small element if found pop() 
      while(s.top() >= curr){
            s.pop();
        }
       
      // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
