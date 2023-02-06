1470. Shuffle the Array.

Code1: 

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for(int i = 0; i<n; i++){
            ans.push_back(nums[i]); 

        if(i+n<nums.size()){
            ans.push_back(nums[i+n]);
            }
        } 
        return ans; 
    }
};

Code2: 
// Approach
// Initialize two pointers first = 0 and second = n , where N is the size of the array.
// Initialise an element max equal to 1 + maximum element of the array and since it is given that maximum value can be 10^3 so we can use 1001.
// Note: You can initialise max to any integer greater than 1000.
// Iterate over the array and perform the following operations:
// If the current index is even:
// Update A[i] = A[i] + (A[first] % mx) * mx
// Increment first by 1.
// If the current index is odd:
// Update A[i] = A[i] + (A[second] % mx) * mx
// Increment second by 1.
// To update the array element back to its original form, divide A[i] by max.

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int len = nums.size();
        
		// to store the pair of numbers in right half of the original array
        for(int i = n; i < nums.size(); i++) {
            nums[i] = (nums[i] * 1024) + nums[i - n];
        }
        
        int index = 0;
		// to retrive values from the pair of numbers and placing those retrieved value at their desired position
        for(int i = n; i < nums.size(); i++, index += 2) {
            nums[index] = nums[i] % 1024;
            nums[index + 1] = nums[i] / 1024;
        }
        
        return nums;
        
    }
};
