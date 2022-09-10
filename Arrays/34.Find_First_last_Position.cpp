34. Find first and last position of element. 
  
  code: 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    
        vector<int> result; 
        int firstIndex = firstPosition(nums, target);
        int lastIndex = lastPosition(nums, target);
        result.push_back(firstIndex);        
        result.push_back(lastIndex);
        return result;
    }
    
    int firstPosition(vector<int>&nums, int target){
        int mid = 0;
        int left = 0;
        int right = nums.size() - 1;
        int ans = - 1;
        
        while(left<=right){
            mid = right + (left - right)/2;
            if(nums[mid] == target){
                ans = mid;
                right = mid - 1;
            }
            else if (nums[mid]< target){
                left = mid + 1;
            }
            else{
                right = mid - 1; 
            }
        }
        return ans;
    }
    
    int lastPosition(vector<int>&nums, int target){
        int mid = 0;
        int left = 0;
        int right = nums.size() - 1;
        int ans = - 1;
        
        while(left<=right){
            mid = right + (left - right)/2;
            if(nums[mid] == target){
                ans = mid;
                left = mid + 1;
            }
            else if (nums[mid]< target){
                left = mid + 1;
            }
            else{
                right = mid - 1; 
            }
        }
        return ans;
        
     }
   
};
