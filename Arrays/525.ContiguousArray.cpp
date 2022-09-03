//525. Contiguous Array
/*
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/
code: 
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      unordered_map<int, int> m;
      int sum = 0;
      int res = 0;
      
      for(int i=0; i<nums.size(); i++){
      if(nums[i] == 0){           
      nums[i] = -1;   // Here we are changing all 0's to -1
        
      }
    }
    for(int i = 0; i<nums.size(); i++){
    sum += nums[i];
      
      if(sum == 0){
      res = max(res, i+1); //if sum is 0 then max lenght will be i+1
      }
      
      if(m.find(sum) != m.end()){ //if sum is in map
      res = max(res, i-m[sum]);
      }
      else {
      m[sum]=i;
      }
    }
      return res;
  }
};
