// Q - 14. Longest Common Prefix 
/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

Code: 
class Solution{
public: 
  string longestCommonPrefix(vector<string>& str){
  int n = str.size();
    if(n == 0) return " ";
    string ans = " ";
    sort(begin(str), end(str));
    string a = str[0];
    string b = str[n-1];
    for (int i = 0; i<a.size(); i++){
    if(a[i]==b[i]){
    ans = ans + a[i];
    }
      else{
      break;
      }
    }
    return ans;
  } 
};
