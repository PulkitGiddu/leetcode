Q - 239. Sliding Window Maximum

Code: 
class Solution{
    public: 
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();   // check for out of bond cases

            while(!dq.empty() && nums[dq.back()] <= nums[i])  // remove smaller elements then a[i]
            dq.pop_back();

            dq.push_back(i);  // after that we will store the current index
            
            if(i>=k-1) 
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
