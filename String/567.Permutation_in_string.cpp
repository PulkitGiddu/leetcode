567. Permutation in string 
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

code: 
class Solution {
private: 
    bool checkEqual(int a[26], int b[26]){
        for(int i = 0; i<26; i++){
            if(a[i] != b[i])
                return 0;
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2) {
        // character count array 
        int count1[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }
        
        // trivese s2 string in window of size s1 length and then compare it. 
        int i = 0;
        int windowSize = s1.length();
        int count2[26] = {0};
        
        // running for the first window 
        while(i<windowSize && i<s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        if(checkEqual(count1, count2))
            return 1;
        
    // process for the next window we have 
    // remove the left most character of window and add next new character into window 
    
        while(i<s2.length()){
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;
            
            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;
            
            i++;
            if(checkEqual(count1, count2))
                return 1;
        }
        return 0;
    }
}; 

// Time complexity :  O(m+n)
// space complexity : O(1)
