Q - Subsets: 
code: 

// Recursive Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {

    private:
    void solve(vector<int>nums, vector<int>output, int index, vector<vector<int>>& ans ){
    // base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude
        solve(nums, output, index + 1, ans);
        
        //Include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1,ans);
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> output;
        int index = 0; 
        solve(nums, output, index, ans);
        return ans; 
    }
};

code2: 
// Iterative Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        ans.push_back({});
        
        for(int i=0; i<n; i++)
        {
            int sz = ans.size();
            for(int j=0; j<sz; j++)
            {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};

Code3: 
// Bit Manipulation
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int num = pow(2, n), i = 0;
        
        while(i<num)
        {
            vector<int> temp;
            for(int j=0; j<n; j++)
            {
                if(i & 1<<j)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
            i++;
        }
        
        return ans;
    }
};
