Q - 402. Remove K Digits. 
Code: 

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res="";
        for(auto c: num){

        //while k>0 and there's still characters in res and last char is greater than current char
            while(res.length() && res.back() > c && k ){ 

                res.pop_back();
                k--;
            }
        
        if(res.length() || c != '0') 
        //to ensure that res doesnt have leading 0's

            res.push_back(c);
        }
        
        //if k is still greater than 0, delete characters from back
        while(res.length() && k){ 
            k--;
            res.pop_back();
        }

        return res.empty()? "0" : res;
        
    }
};

