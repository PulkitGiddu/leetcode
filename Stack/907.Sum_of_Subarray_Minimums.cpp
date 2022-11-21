Q - 907. Sum of Subarray Minimums

Code: 
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
            stack<int> s1, s2;
            int n = A.size();
            vector<int> next_smaller(n), pre_smaller(n);
            for(int i = 0; i<n; i++){
                    next_smaller[i] = n - i - 1; // right side of array 
                    pre_smaller[i] = i;  // triversing the left side for smaller elements 
            }
            
            // finding min in s1 
            for(int i = 0; i<n; i++){
                    while(!s1.empty() && A[s1.top()] > A[i]){
                            next_smaller[s1.top()] = i - s1.top()-1;
                            s1.pop();
                    }
                    s1.push(i);
            }
            
            // Finding the min in right i.e. s2
            for(int i = n - 1; i>=0; i-- ){
                    while(!s2.empty() && A[s2.top()] >= A[i]){
                            pre_smaller[s2.top()] = s2.top() - i - 1;
                            s2.pop();
                    }
                    s2.push(i);
            }
            
            // at last storing the right and left min in ans using formula
            // submission A[i] * ( pre+smaller[i] + 1) * (next_smaller[i] + 1)
            long ans = 0;
            int mod = 1e9+7;
            for(int i = 0; i<n; i++){
//                     ans += (A[i]*(pre_smaller[i] + 1)*(next_smaller[i] + 1) );
                    ans = ( ans + (long)A[i] * (pre_smaller[i] + 1) * (next_smaller[i] + 1)) % mod;
                    ans %= mod;
            }
            return ans; 
    }
};
