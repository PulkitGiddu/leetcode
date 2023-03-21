2348. Number of Zero-Filled Subarrays

Code: 

class Solution {
public:
    long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, ans = 0;
        for(int x : nums){
            if(x)
            cnt = 0; 
            else
            cnt++;

            ans += cnt;
        }
        return ans;
    }
};
