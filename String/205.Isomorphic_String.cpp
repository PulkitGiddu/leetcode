//Q - 205. Isomorphic String
/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character
*/

Code: 
approch 1: 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, int > mp; 
        set<char> x;
        for(int i = 0; i<n; i++){
            if(mp.count(s[i]) == 0 && x.count(t[i]) == 0){
                mp[s[i]] = t[i];
                x.insert(t[i]);
            }
            else if (mp.count(s[i]) == 0 && x.count(t[i]))
                return false;
            else if(mp[s[i]] != t[i])
                return false;
        }
        return true;
    }
};

approch 2: 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        char seen[128] = {};
        for(int i = 0; i<n; i++){
            char c = s[i];
            if(!seen[c]){
                for(char s : seen) if(s == t[i]) return false;
                seen[c] = t[i];
            }
            else if(seen[c] != t[i]) return false;
        }
        return true; 
    }

};
