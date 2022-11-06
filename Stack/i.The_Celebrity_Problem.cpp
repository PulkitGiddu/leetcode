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

Code: 
//better explaniantion
// O(N)approach using stacks.

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M,int a, int b){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    public:

    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
//first we push the people 0,1,2...etc on to the stack.

    {
      stack<int> s;
      for(int i=0;i<n;i++){
          s.push(i);
        }
//now we compare the the top two values of the stack for whether they know each other or not, knows function is written above.
//if A knows B then A is not a celebrity and B is re added on to the  staack....this process is continued until only a single element present on stack.

        while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(M,a,b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
     }

        //verify thhe value present at the stack for whether its a celebrity or not, as it could be or not a celebrity, 
        //just check rows and columns for whether it knows everyone or not, also whether everyone knows them or not.

        int potential=s.top();
        int colcount=0;
        int rowcount=0;
        
        for(int i=0;i<n;i++){
            if(M[i][potential]==1){
                colcount++;
            }
            if(M[potential][i]==0){
                rowcount++;
            }
            if(colcount==n-1&&rowcount==n){
                return potential;
            }
        }

        return -1;

//we return the answer depending on the result, all of these use N comparisons with no nested loops, hence its 0(N) TC....

        

        

    

    }

};
