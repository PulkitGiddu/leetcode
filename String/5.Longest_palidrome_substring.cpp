Q - 5. Longest palindrome substring: 
/*

*/
code: 
/*
This approach takes O(n^2) time complexity, O(1) space complexity, where n is the length of s.
For each character s[i], we get the first character to its right which isn't equal to s[i].
Then s[i, right - 1] inclusive are equal characters e.g. "aaa".
Then we make left = i - 1, while s[left] == s[right], s[left, right] inclusive is palindrome, and we keep extending both ends by left -= 1, right += 1.
Finally we update the tracked longest palindrome if needed.
*/
class Solution{
    public:
string longestPalindrome(string s) {
    
    if (s.empty()) return "";
    
    if (s.size() == 1) return s;
    
    int min_start = 0, max_len = 1;
    
    for (int i = 0; i < s.size();) {
        if (s.size() - i <= max_len / 2) break;
        int j = i, k = i;
        
        while (k < s.size()-1 && s[k+1] == s[k]) 
        ++k; // Skip duplicate characters.
        i = k+1;
        
        while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) 
        { ++k; --j; } // Expand.
        
        int new_len = k - j + 1;
        if (new_len > max_len) 
        { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}
};
