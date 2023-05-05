1456. Maximum Number of Vowels in a Substring of Given Length

Code: 
class Solution {
public:
    int isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int max_vow = 0, cur_vow=0;
            for(int i=0;i<s.size();i++){
                // adding the new elemnt to array
                cur_vow += isVowel(s[i]);
                if(i>=k)
                cur_vow -= isVowel(s[i-k]); // deleting the element 
                max_vow = max(max_vow, cur_vow);
            }
        return max_vow;
    }
};
