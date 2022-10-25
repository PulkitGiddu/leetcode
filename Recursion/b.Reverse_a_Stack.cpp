Q- Reverse a stack usning recursion: 
code: 
class Solution{
public:
    void insertAtBottom(stack<int> &s, int element){
        // base case
        if(s.empty()){
            s.push(element);
            return;
        }
        int num = s.top();
        s.pop();
        
        // recursive call
        insertAtBottom(s, element);
        s.push(num);
        
        
    }
    void Reverse(stack<int> &s){
        // BASE CASE 
        if(s.empty()) {
            return;
        }
        int num = s.top();
        s.pop();
        
        // recursive call
        Reverse(s);
        
        insertAtBottom(s, num);
        
    }
};
