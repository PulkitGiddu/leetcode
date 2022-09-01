//check if the array is sorted and rotated
/*

*/

Code:

class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count=0;
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%n])count++;
        }
        
        return count<=1;
    }
};

/*class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 1; i<n; i++){
            if(nums[i-1] > nums[i]){
                count++;
            }
         }
        if(nums[n-1] > nums[0]){
            count++;
            
            return cout <= 1;
        }
         
    }
};
*/
