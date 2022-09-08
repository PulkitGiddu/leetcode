169. Majority elements 
/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
code: 
//Optimal approch using moore's voting system.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int pulkit = 0; //Pulkit is candidate 
        for(int num : nums){ // now we were iterating in data structures num 
            if(count == 0){
                pulkit = num;
            }
            if(num == pulkit) count += 1;
            else count -= 1;
        }
        return pulkit;
        
    }
};

//Time complexity = O(n)
//Space complexity = O(1)
