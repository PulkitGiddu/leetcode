Q - String_to_Integer_(atoi) 
  
code: 
class Solution {
    public :
    int myAtoi(string s) {
        if(s.length()==0) return 0;

        int i=0;
         while(i<s.size() && s[i]== ' ') {
             i++;
         }     
        s = s.substr(i); //i ---> last of string
        
        int sign = +1;
        long ans = 0;
        
        if(s[0] == '-') sign = -1;
        
        int MAX = INT_MAX, MIN = INT_MIN;
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
		
        while(i < s.length()) {
            if(s[0] == ' ' || !isdigit(s[i])) break;
            
            ans = ans * 10 + s[i]-'0';
            if(sign == -1 && -1*ans < MIN) return MIN;
            if(sign == 1 && ans > MAX) return MAX;
            
            i++;
        }
        
        return (int)(sign*ans);
    }
};

Code2: 
class Solution {
public:
    int myAtoi(string s) {
        
        // helper variables
        int res=0;
        int i=0;
        int sign=1;
		
        while(i<s.size()&&s[i]==' ')i++;  //ignore leading white space
        
        if(s[i]=='-'||s[i]=='+')          //check if number positve or negative
        {
            sign=s[i]=='-'?-1:1;
            i++;
        }
        // now iterate across digits if any
		// should only be in range 0-9
        while(i<s.length()&&(s[i]>='0'&&s[i]<='9'))  //traverse string till nondigit not found or string ends
        {
            int digit=(s[i]-'0')*sign;
            if(sign==1 && (res>INT_MAX/10 || (res==INT_MAX/10 && digit>INT_MAX%10))) return INT_MAX; //check for overflow
            if(sign==-1 &&(res<INT_MIN/10 || (res==INT_MIN/10 && digit<INT_MIN%10))) return INT_MIN; //check for underflow
            
            res=res*10+digit; // update res
            i++;
        }
    
    return res;
    }
};

// in both cases time will be O(n) and we are not using any extra space so O(1). 
