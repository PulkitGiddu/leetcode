Q - 232. Implement Queue using Stacks
Code: 

// Queue implementation using stack 
class MyQueue {
  // making two stacks as input and output 
    stack<int> input;
    stack<int> output;
        
    public:
    // initialize data structures
    MyQueue(){
        input = stack<int>();
        output = stack<int>();
    } 
    
    // push element into queue 
    void push (int x){
            
        input.push(x);
    }

    // remove the element form in fornt of queue and returns that element
    
    int pop(){
        if(output.empty())
        {
        while(input.empty() == false ){
        output.push(input.top());
        input.pop();
        }
    }
        int val = output.top();
        output.pop();
        return val;
}
    
    // this up condition will make sure that all elements of input are inserted to output. 
    int peek() {    
    if(output.empty()) 
    {        
        while( input.empty() == false){
        output.push(input.top());
        input.pop();
        }
    }
        return output.top();
 }

    // Returns weather the queue is empty or not 
    bool empty()
    {
    return output.empty() && input.empty();
    }
};

/*
Time Complexity --->  O(1)
               -
                 -
                   -> O(1) amortised. 
Space Compelexity ---> O(2 N)
*/ 
