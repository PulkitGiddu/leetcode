Q - Sort Colors
/*
Algorithm:
Consider three pointers low = 0, mid = 0, high = nums.size() - 1
The algorithm ensures that at any point, every element before low is 0, every element after high is 2, every element in between are either 0, 1 or 2 i.e. unprocessed.
We'll use mid pointer to traverse and check the array elements i.e. while(mid <= high). Three cases are possible:
nums[mid] == 0 In this case swap(nums[low], nums[mid]) and increment both low and mid pointer i.e. low++ mid++
nums[mid] == 1 In this case mid++
nums[mid] == 2 In this case swap(nums[mid], nums[high]) and decrement high pointer i.e. high--

Example:
Consider nums[] = [0 1 1 0 1 2 1]

Iteration 1:
low = 0, mid = 0, high = 6
nums[mid] == 0
swap(nums[low++], nums[mid++]
[0 1 1 0 1 2 1]

Iteration 2:
low = 1, mid = 1, high = 6
nums[mid] == 1
mid++
[0 1 1 0 1 2 1]

Iteration 3:
low = 1, mid = 2, high = 6
nums[mid] == 1
mid++
[0 1 1 0 1 2 1]

Iteration 4:
low = 1, mid = 3, high = 6
nums[mid] == 0
swap(nums[low++], nums[mid++]
[0 0 1 1 1 2 1]

Iteration 5:
low = 2, mid = 4, high = 6
nums[mid] == 1
mid++
[0 0 1 1 1 2 1]

Iteration 6:
low = 2, mid = 5, high = 6
nums[mid] == 2
swap(nums[mid], nums[high--]
[0 0 1 1 1 1 2]

Iteration 7:
low = 2, mid = 5, high = 5
nums[mid] == 1
mid++
[0 0 1 1 1 1 2]

Iteration 8:
low = 2, mid = 6, high = 5
mid > high
Exit the loop

*/

Code: 
class Solution {
public:
    void sortColors(vector<int>& nums) {
 
        int lo = 0; //At first index
        int mid = 0; // at first index
        int hi = nums.size()-1;
        
        while(mid <= hi){
            switch(nums[mid]){
                case 0:
                    swap (nums[lo++], nums[mid++]);
                    break;
                    
                case 1:
                    mid++;
                    break;
                    
                case 2:
                    swap(nums[mid], nums[hi--]);
                    
            } 
        }
    }
};


        
 
