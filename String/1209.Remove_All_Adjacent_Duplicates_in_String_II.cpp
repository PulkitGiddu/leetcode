Q - 1209. Remove All Adjacent Duplicates in String II
/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1:
Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Example 2:
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Example 3:
Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
*/

Code:
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k) return s;
        
        stack<pair<char,int>> stack;
        for(int i=0; i<n; ++i){
            if(stack.empty() || stack.top().first != s[i]){
                stack.push({s[i],1});  
            } 
            else{
                auto prev = stack.top();
                stack.pop();
                stack.push({s[i], prev.second+1});
            }
            if(stack.top().second==k) stack.pop();
        }
        
        string ans = "";
        while(!stack.empty()){
            auto cur = stack.top();
            stack.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
