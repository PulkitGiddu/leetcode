// 126. Single numbers
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
*/
code
class Solution {
public:
     int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    // for(auto i: nums){
    // mp[i]++;
    //    }
    // for(auto i:mp){
    // if(i.second==1)
    // return i.first;
    //    }
    // return -1;
    
    int a = 0;  //first convert all number to binary then XOR two same binary = 0 and unique be be returned.
    
    for (auto i:nums){
        a= a xor i;
    }
    return a;
    }
};

 
