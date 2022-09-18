1283. Find the Smallest Divisor Given a Threshold 
/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer.

Example 1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

Example 2:
Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
 

Constraints:
1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106
*/
Code: 
Solution 1: 

class Solution {
public: 
  int smallestDivisor(vector<int>& nums, int threshold){
  int l = 1,r = 1000001;
    int ans = 0;
    while(l<=r){
    int mid = l + (r - l)/2;
      long long int sum = 0;
      
      for(int i = 0; i <nums.size(); i++){
      if(nums[i]%mid == 0){
      sum +=(nums[i]/mid);
      }
        else{
        sum +=(nums[i]/mid)+1;
          }
      }
      if(sum>threshold){
      l = mid + 1;
      }
      else {
      ans = mid;
        r  = mid - 1;
      }
    }
    return ans;
  }
};

Solution 2: 
int findSum(int mid, vector<int>& nums){
    int sum = 0;
    for(auto it = nums.begin(); it != nums.end(); it++)
        sum = sum+ceil((float)(*it)/mid);
    return sum; 
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maximum = *max_element(nums.begin(),nums.end());
        int left = 1, right = maximum, sum, divisor;
        while(left<=right){
            int mid = left + (right - left)/2;
            sum = findSum(mid, nums);
            
            if(sum <= threshold){
                divisor = mid;
                right = mid -1;
            }
            else
                left = mid + 1;
        }
        return divisor;
    }
};

