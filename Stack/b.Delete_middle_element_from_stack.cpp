Q - Delete middle element from stack 
Code: 
#include <bits/stdc++.h> 
void solve(stack<int>& inputStack, int count, int size){
    // base case
    if(count == size/2){
        //delete middle element 
        inputStack.pop();
        return;
    }

    //Storing the top element into num variable. 
    int num = inputStack.top();
    inputStack.pop();
    

    // recursiveCall
    solve(inputStack, count + 1, size); 

    // now pushing the num value into stack back which early was taken out
    inputStack.push(num); 
    
}
void deleteMiddle(stack<int>& inputStack, int N){
    int count = 0;
    solve(inputStack, count, N);
}  
