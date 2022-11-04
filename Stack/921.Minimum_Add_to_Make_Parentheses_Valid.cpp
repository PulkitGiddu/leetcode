Q - 921. Minimum Add to Make Parentheses Valid 
Code: 

class Solution {
public:
int minAddToMakeValid(string s) 
{
    stack<char> st;//create a Stack
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')//whenever their is open bracket insert on stack
            st.push('(');
        else 
        {
            if(!st.empty() && st.top()=='(')//if their is open bracket on the top of stack and stack is not empty, then pop
                st.pop();
            else
                st.push(')');//otherwise push closing bracket on stack
        }
    }
    return st.size();//atlast return stack size
}
};
