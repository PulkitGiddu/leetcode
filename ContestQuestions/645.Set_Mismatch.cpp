Q - 645.Set_Mismatch
  
  Code: 
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int N = nums.size(), sum = N * (N + 1) / 2;
//         vector<int> ans(2);
//         vector<bool> seen(N+1);
//         for (int num : nums) {
//             sum -= num;
//             if (seen[num]) ans[0] = num;
//             seen[num] = true;
//         }
//         ans[1] = sum + ans[0];
//         return ans;
//     }
// };
class Solution{
    public: 
    vector<int> findErrorNums(vector<int>& nums){
        vector<int> ans; // created new vector for storing our ans 
        unordered_set<int> s;  // New set will will store element present in array
        int sum = 0;           // if element comes twice then simply move on to next element 
        for(auto x: nums){
            if(s.find(x) != s.end()){
                ans.push_back(x);
            }
            else{             // here we are taking out sum of all elemets in set 
                s.insert(x);           
                sum += x;
            }
        }
        int n = nums.size();
        int t = n*(n+1)/2;   
        ans.push_back(t - sum); // this will take the ans vector ans set elements ans subtract that to give missing element.

        return ans;
    }
};
