3. Longest Substring Without Repeating Characters 

Code: 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1); // 256 because a string can have 256 different characters 
        
        // keeping left and right pointer at starting index. 
        int left = 0, right = 0; 
        int n = s.size();
        int len = 0;

        while(right<n){
            if(mpp[s[right]] != -1) // character at right index exist or not 
            left = max(mpp[s[right]] + 1, left); // exist then take that and add  1. 

            mpp[s[right]] = right; // here we are checking the last seen at this index i.e (a,0)  (a, 4) first seen on 0. 
            
            len = max(len, right - left + 1);
            right++;

        }
        return len; 

    }
};
