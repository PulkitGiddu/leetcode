Q - 735. Asteroid Collision..
	

Code: 

class Solution{
public: 
  vector<int> asteroidCollision(vector<int>& asteroids){
  vector<int> v;
    stack<int> s;
    for(auto x: asteroids){
    if(x>0) s.push(x);
      else{
      // case1: when top is less then x 
        while(s.size() > 0 && s.top() > 0 && s.top() < -x){
        s.pop();
        }
        // case2: when both of same size
        if(s.size() > 0 && s.top() == -x){
        s.pop();
        }
        
        // case3: when top is greater
        else if(s.size() > 0 && s.top() > -x){
        // do nothing 
        }
        
        // case 4: when both asteroids are having same direction
        else{
        s.pus(x);
        }
      }
    }
    
    while(!s.empty()){
    v.push_back(s.top());
    s.pop();
    }
    reverse(v.begin(), v.end());
    return v;
  }
};


Code2:

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || s.empty()) {
                s.push(ast[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(ast[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(ast[i]);
                    }
                }
            }
        }
		// finally we are returning the elements which remains in the stack.
		// we have to return them in reverse order.
        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
