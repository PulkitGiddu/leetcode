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

