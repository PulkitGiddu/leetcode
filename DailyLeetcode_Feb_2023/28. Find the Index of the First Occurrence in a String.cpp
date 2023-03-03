28. Find the Index of the First Occurrence in a String

Code:
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()){
            return -1;
        }

        int j = 0; 
        for(int i = 0; i<haystack.size() - needle.size() + 1; i++){
            if(haystack[i] == needle[j]){
                int l = i; 
                while(j<needle.size() && haystack[l] == needle[j]){
                    l++; 
                    j++; 
                }
                if(j == needle.size()){
                    return i; 
                }
            }  
            j = 0;
        }
        return -1;
    }
};
