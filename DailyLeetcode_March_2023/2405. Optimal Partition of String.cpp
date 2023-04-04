2405. Optimal Partition of String 

Code: 

// using unordered_set
class Solution {
public:
    int partitionString(string s) {
        set<char> ch; 
        int count = 1; 

        for(int i = 0; i<s.size(); i++){

        // of the s[i] has alredy occured then its time to place a portion here & make a new substring
        if(ch.find(s[i]) != ch.end()){
            count++; 
            ch.clear(); 
        }
        // upcomming chracter will for sure go into set.
        ch.insert(s[i]);
    }
    return count; 
        
    }
};

Code 2 : 

// Insted of using set we can have array to store & check if the character has occured again or not 

class Solution{
    public: 
    int partitionString(string s){
        int last_pos[26] = {}, partitions = 0, last_end = 0;

        for(int i = 0; i<s.length(); i++){
            if(last_pos[s[i] - 'a' ] >= last_end){
                partitions++; 
                last_end = i + 1;
            }
            last_pos[s[i] - 'a'] = i + 1;
        }
        return partitions;
    }
};


Code3: 
// for the same operatio to check if the character has occured or not, we use a BITS -> if the bit is set - that means char has occured before 

// -> if the bit is unset - that means char has not occured before
class Solution{
    public: 
    int partitionString(string s){
        int i = 0, ans = 1, flag = 0;
        while(i < s.size()){
            int val = s[i] - 'a'; 

            // check that the char bit is set  
            if(flag & (1 << val) ){
                flag = 0; 
                ans++;
            }

            // now set the bit of the char 
            flag = flag | (1 << val);
            i++; 
        }
        return ans;
    }
};
