// Q- 796.Rotate String
/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.
 
Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false
*/
Code: 
class Solution{
    public: 
bool rotateString(string A, string B) 
    {
        if(A.size() != B.size())
            return false;
        if(A == B)      //for empty strings
            return true;
        
        int len = B.size();
        while(len--)
        {
            if(A == B)
                return true;
            A = A.substr(1) + A[0];     // one shift on A
        }
        return false;
    }
};
