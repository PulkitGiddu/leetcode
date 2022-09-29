//Q -1175. Prime Arrangements
code:
int M = pow(10, 9) + 7;
class Solution {
public:
    int numPrimeArrangements(int n) {
        
        vector<bool> seive(n + 1, true);
        seive[1] = false;
        int no_of_primes = 0;
        for(int i = 2; i <= n; i++)
            if(seive[i])
            {
                no_of_primes++;
                int tmp = 2;
                while(tmp * i <= n)
                    seive[tmp * i] = false, tmp++;
            }
        
        long long ans = 1;
        for(int i = 1; i <= no_of_primes; i++)
            ans = (ans * i) % M;
        
        for(int i = 1; i <= n - no_of_primes; i++)
            ans = (ans * i) % M;
            
        return ans;
    }
};
