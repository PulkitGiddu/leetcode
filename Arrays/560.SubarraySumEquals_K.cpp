//560. Subarray Sum Equals K
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 
*/

Code: 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> m;
        int count = 0;
        int sum = 0; 
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if (sum == k) count++;
            
            if(m.find(sum - k) != m.end()){
                count   = m[sum -k] + count;
            }
            if(m.find(sum) != m.end()){
                m[sum]++;
            }
            else {
                m[sum]  = 1;

            }

        }
        return count;
            
        
    }
};

// Time complexicty  --> O(n)
// Space complexicity --> O(n)
