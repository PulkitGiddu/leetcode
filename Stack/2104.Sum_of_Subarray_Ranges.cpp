Q - 2104. Sum of Subarray Ranges

Code: 
class Solution{
public:
long long subArrayRanges(vector<int>& A) {
        long long res = 0;
        for (int i = 0; i < A.size(); i++) {
            int ma = A[i], mi = A[i]; // two variable declaring maximum and minimum 
            for (int j = i; j < A.size(); j++) {
                    
                ma = max(ma, A[j]);
                mi = min(mi, A[j]);
                    
                res += ma - mi; // the difference between max and min value.
            }
        }
        return res;
    }
};
