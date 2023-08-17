239. Sliding Window Maximum

Code :  T.C : O(n), S.C : O(k) 
  class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(); 

        deque<int> dq; 

        vector<int> result; 

        for(int i = 0; i<n; i++){
            
            // step 1 : When new element comes nums[i], make space for it. (window size can't be greter than k )
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front(); 
            }

            // Step 2 : When nums[i] comes no need to keep small elements
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back(); 
            }

            // Step 3 : now push i index in the deque
            dq.push_back(i);

            // Step 4 : i >= k-1 then dq.front is our ans for that window
            if(i >= k - 1){
                result.push_back(nums[dq.front()]); 
            }
        }
        return result;
    }
};
