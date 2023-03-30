87. Scramble String

Code: 

class Solution {
public:
    map<string, bool> mp; 
    bool isScramble(string s1, string s2) {
        // base case.
        int n = s1.size();
        if(s1 == s2) return true; 
        if(n == 1) return false; 

        // this key is to make sure that this string pair has come before or not.
        string key = s1+" "+s2; 

        if(mp.find(key) != mp.end()) // find the key  -> if yes -> already computed,
        return mp[key];

        // go to every split position 
        for(int i = 1; i<n; i++){

            // compare s1 left with s2 left and s1 right with s2 right.
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
            return mp[key] = true; 
            
            // compare s1 left with s2 right and s1 right with s2 left.
            if(isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i)))
            return mp[key] = true;
        }
        return mp[key] = false;    
    }
};
