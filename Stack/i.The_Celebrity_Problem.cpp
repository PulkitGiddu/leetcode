Q- The Celebrity Problem

Code: 
class Solution 
{
    private: 
    bool knows(vector<vector<int> >& M, int a, int b, int n){
        if(M[a][b] == 1)
           return true;
        else
           return false;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        // step1 : Push all elements into the stack 
        for(int i = 0; i<n; i++){
            s.push(i);
        } 
        
        //step 2:
        
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        //candidate
        int ans  = s.top();
        // step3: single element in stack is potential celebrity
        //So verify that 
        
        //bool rowCheck = false;
        int zeroCount = 0;
        
        //For row check if all zeros then 
        for(int i = 0; i<n; i++){
            if(M[ans][i] == 0)
            zeroCount++;
        }
        // check for all zeros 
        if(zeroCount != n){
            return -1;
            //rowCheck = true;
        }
        
        // coloum check 
        // bool colCheck = false;
        int oneCount = 0;
        
        for(int i = 0; i<n; i++){
            if(M[i][ans] == 1)
            oneCount++;
        }
        
        if(oneCount != n-1){
            return -1;
            //colCheck = true;
        }
        
        // if(rowCheck == true && colCheck == true){
        //     return ans; 
        // }
        // else{
        //     return -1;
        // }
        return ans;
    
    }
};
