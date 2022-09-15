540. Single element in sorted array 4
  
/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/  
Code:
class Solution{
    public:
int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
    
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(m%2){
				// (even odd) i.e. we are on the left side of unique element--> go right
                if(nums[m-1]==nums[m])
                    l = m+1;
				// (even odd) pair violated, happens on the right side of unique element--> go left
                else{
                    r = m-1;
                }
            }else{
				// (even odd) i.e. we are on the left side of unique element--> go right
                if(nums[m]==nums[m+1]){
                    l = m+1;
				// (even odd) pair violated, happens on the right side of unique element--> go left
                }else{
                    r = m-1;
                }
            }
        }
        return nums[l];
    }
};
