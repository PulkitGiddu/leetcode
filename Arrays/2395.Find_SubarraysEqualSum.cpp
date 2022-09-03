Leetcode contest question:
//2395. Find Subarrays With Equal Sum
/*Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.

Return true if these subarrays exist, and false otherwise.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
Example 2:

Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.
Example 3:

Input: nums = [0,0,0]
Output: true
*/
Code:

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
      
      if(nums.size()<=2) return false;
      unordered_map<int, int> m;
      
      vector<int> pre(nums.size(), 0);
        for(int i = 0; i<nums.size(); i++){
            if(i==0){
                pre[i] = nums[i]; //pre = previous
            }
            
            if(i>0){
                m[pre[i]]++;
            }
            
            if(i+1 < nums.size()){
                pre[i+1] = nums[i] + nums[i+1];
            }
        }
        
        for (auto i : m){
            if(i.second >= 2 ) return true; 
        }
        return false;   
    }    
};

//2nd approch 
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=1;i<n;i++){
            int sum = nums[i]+nums[i-1];
            mp[sum]++;
            if(mp[sum]>1) return true;
        }
        return false;
    }
};
