Q- 2423. Remove Letter To Equalize Frequency
/*
You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word 
so that the frequency of every letter present in word is equal. Return true if it is possible to remove one letter so that the frequency of all letters in 
word are equal, and false otherwise.

Note:
The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot chose to do nothing.
 
Example 1:
Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.

Example 2:
Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.
*/
Code1:
class Solution {
public:
    bool equalFrequency(string word) {
        map<char , int> mp;
        int cnt = 0;
        for(int i = 0 ; i<word.length() ; i++){
            mp[word[i]]++;
        }
        
        
        
        for(auto it: mp){
            int val =0;
            set<int> st;
            for(auto it1: mp){
                if(it1.first == it.first){
                if(it.second-1 > 0){
                    st.insert(it.second-1);
                }
                    continue;
                }
                
                st.insert(it1.second);
                
                
            }
            
            if(st.size() == 1){
                return true;
            }
        }
        
        
        for(auto it: mp){
            if(it.second == 1){
                cnt++;
            }
        }
        
        if(cnt == word.length()){
            return true;
        }
        
        return false;
    }
};
Code 2:
class Solution {
public:
    bool equalFrequency(string word) {
        bool ans = false;
        
        for(int i=0;i<word.size();i++) // going to every index
        {
			if(ans) // if at any point ans becomes true we return true
			return true;
            unordered_map<char,int> mp;
            int total = 0;
            for(int j=0;j<word.size();j++)
            {
                if(j==i) // skipping the current index
                    continue;
                mp[word[j]]++;
                total++;
            }
            int x = total/mp.size(); // every characters freq should be equal
            bool flag = true;
            for(auto m:mp)
            {
                if(m.second!=x) // if the condition is violated then the result is false for this case
                {
                    flag = false;
                    break;
                }    
            }
            if(flag) // if the condition was not violated then it is our ans
                ans = ans || true;
        }
        return ans;           
    }
};
