Q- 1922. Count Good Numbers 
code:

class Solution {
public:
//     int mod = 1e9+7;
//     long long power(long long x, long long y){
//         // base condition
//         if(y == 0) return 1;
//         long long ans = power(x,y/2);
//         ans*=ans; // ans  = (x,y/2)*(x,y/2)
//         ans%=mod;
//         if(y%2)ans*=x; // y is odd
//         ans%=mod;
//         return ans; 
//     }
        
//     int countGoodNumbers(long long n) {
//         long long odd = n/2;
//         long long even = n/2 + n%2;
//         return (power(5,even)*power(4,odd))%mod;
//     }
// };
  
  code2: 
  
    long long int modExpo(long long x, long long n, int M){
        //base conditions 
        if(n==0) return 1; 
        if(n%2 == 0){
            long long y = modExpo(x,n/2,M);
            return ((y%M)*(y%M))%M;
        }
        else{
            return((x%M) * (modExpo(x,n-1,M)%M))%M;
        }
        
    }
    
    int countGoodNumbers(long long n ){
        int M = 1e9+7;
        if(n%2 == 0){
            return((modExpo(5,n/2,M)%M) * (modExpo(4,n/2,M)%M))%M;
        }
        return((modExpo(5,n/2+1,M)%M) * (modExpo(4,n/2,M)%M))%M;
    }
};

//T.C = 0(logn)
//S.C = O(1)
