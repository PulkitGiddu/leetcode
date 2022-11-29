Q - 67. Add Binary

Code: 
class Solution{
    public: 
    string addBinary(string a, string b){
        int alen = a.length();            // Calculating len for a string 
        int blen = b.length();            // Calculating len for a string 
        int i = 0, carry = 0;
        string ans ="";    
            while(i<alen || i<blen || carry != 0){
                int x = 0;
                if(i<alen && a[alen - i - 1] == '1'){
                    x = 1;
                }
                        
                int y = 0;
                if(i<blen && b[blen - i - 1] == '1'){
                    y = 1;
                }
                ans = to_string ((x + y + carry)%2) + ans;
                carry = (x+y+carry)/2;
                i += 1;
                }
        return ans;   
   }
};

Code: 

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if(carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
