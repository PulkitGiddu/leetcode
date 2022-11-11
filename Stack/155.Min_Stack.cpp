Q - 155. Min Stack. 
  
Code: 
class MinStack {
public:
  
   // created two stacks one for pushing all element and one is to keep track of min       
    stack<int> stack1, minStack;
  
    MinStack() {        
    }

  // if minstack is empty or value which we have is less then push into minstack as well as into main stack
    void push(int val) {
        if(minStack.empty() || val <= minStack.top()){
                minStack.push(val);
        }
            stack1.push(val); 
    }
    
    void pop() {
      // check augar first stack mae jo top value hai and minstack mae jo value hai dono same hai pop kr do dono stack sae 
        if(stack1.top() == minStack.top()){
              minStack.pop();  
        }
            stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
       return minStack.top(); 
    }
};


Code: T.C = O(1)
      S.C = O(1)
  
  #include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};
//

