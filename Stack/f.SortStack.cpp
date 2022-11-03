Q - Sort a stack
Code: 

#include <bits/stdc++.h> 
void sortedVal(stack<int> &stack, int nums){
    // base case 
    if(stack.empty() || (stack.top() < nums)){
        stack.push(nums);
        return;
    }
    
    int x = stack.top();
    stack.pop();
    
    // recursive call 
    sortedVal(stack, nums);
    
    stack.push(x);
    
}
void sortStack(stack<int> &stack)
{
	// base conditio
    if(stack.empty())
        return; 
    
    int num = stack.top(); 
    stack.pop();
    
    // recursive call 
    sortStack(stack); 
    
    sortedVal(stack, num);
}
