Q - 22. Generate Parentheses
Code: 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;   // created new resultant string where parenthesis will be stored
        addingpar(res, "", n, 0);          
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }  // apply close bracket and moving forward. 
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); } // apply open bracket and moving forward. 
    }
};
