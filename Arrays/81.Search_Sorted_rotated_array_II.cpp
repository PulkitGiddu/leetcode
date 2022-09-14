Q - 81. Search In Sorted Rotated Array

code: 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        
        while(s <= e)
        {
            int mid = s + (e-s) / 2;
            if (nums[mid] == target)
                return true;
            if((nums[s] == nums[mid]) && (nums[e] == nums[mid]))
            {
                s++;
                e--;
            }
			// first half
			// first half is in order
            else if(nums[s] <= nums[mid])
            {
				// target is in first  half
                if((nums[s] <= target) && (nums[mid] > target))
                    e = mid - 1;
                else
                    s = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[e]>= target))
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        return false;
    }
	
};


//
Code: 
class Solution {
public:
    int search(vector<int>& nums, int target) {
    int s = 0;
    int e = nums.size()-1; 
    int mid;
        
    while(s <= e){
        
            mid= s + (e - s)/2;
            if(nums[mid]==target)
                return true;
            if((nums[s] == nums[mid]) && (nums[e] == nums[mid]))
            {
                s++;
                e--;
            }
            else if(nums[s]<=nums[mid])
            {
                if(target<nums[mid] && target>=nums[s])
                    e=mid-1;
                else
                    s=mid+1;
            }
            
            else
            {
                if(target>nums[mid] && target<=nums[e])
                   s=mid+1;
                else
                    e=mid-1;
            }
            
        }
        return false;
    }
};


