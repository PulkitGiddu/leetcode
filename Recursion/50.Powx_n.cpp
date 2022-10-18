 Q - 50. Pow(x, n 
code: 
class Solution {
public:
    double myPow(double x, int n, double res = 1) {
        return n ? myPow(x * x, n / 2, n % 2 ? (n > 0 ? res * x : res / x) : res) : res;
    }
};
             
// T.C = O(N)
// S.C = O(1)
