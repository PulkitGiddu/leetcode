7. Reverse Interger : 

/*
ans = ans * 10 + digit.
n = n/10.

while ( n /= 0)
{
int digit  = n % 10;
ans = (ans * 10) + digit;
n = n/10;

{ // check for these two conditions also.
ans > INT_MAX/10
ans < INT_MIN/10
}
}
*/

Code: 
class Solution {
public:
    int reverse(int x) {
        
        int ans = 0;
        while (x != 0){
        int digit = x % 10;
            if((ans > INT_MAX/10) || (ans < INT_MIN/10)){
                return 0;
            }
        
        ans = (ans * 10) + digit;
        x = x / 10;
        
        }
        return ans;
    }
}; 
