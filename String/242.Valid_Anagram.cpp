//Q - 242. Valid Anagram
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/
Code: 
class Solution {
public:
    bool isAnagram(string s, string t) {
// Simply sort the two functions and if both are sorted then simply return that value 
//         if(s.size() != t.size() ) return false;
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }

// Approch 2 : Time Complexity: O (n) Space Complexity: O(n) (Some may argue it is O (1) because space            will be constant, they are correct too.)
//         if(s.size() != t.size()) return false; 
//         unordered_map<char, int> m;
//         for(char c : s) m[c]++;
//         for(char c : t){
//             m[c]--;
//             if(m[c]<0) return false;
//         }
//         return true; 
        
//Implementing Hashmap as an Array of constant size
// Time complexity: O(n)
// space Complexity: O(1)
        if(s == t) return true;
        if(s.size() != t.size()) return false;
        int m[26] = {};
        for(int i = 0; i<s.size(); i++){
            m[s[i] - 'a']++;
            m[t[i] - 'a']--;
        }
        for(int i = 0; i<26; i++){
            if(m[i]) return false;
        }
        return true;
    }
};
