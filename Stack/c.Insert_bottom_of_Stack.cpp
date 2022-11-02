Q - insert at bottom of the stack. 
  code: 
#include <bits/stdc++.h>
void solve(stack<int>& s, int x){
    // base case 
    if(s.empty()){
        s.push(x);
        return;
    }
    
  // no ko store krva lia and then pop kia 
    int num = s.top();
    s.pop();
    
    // recursive call
    solve(s, x);
    
  // vapis aatey aatey num ko push kr dia stack mae
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
   solve(myStack, x);
    return myStack;
}
