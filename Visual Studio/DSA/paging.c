// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//     int s = 0;
//     int e = nums.size()-1; 
//     int mid;
        
//     while(s <= e){
        
//             mid= s + (e - s)/2;
//             if(nums[mid]==target)
//                 return true;
//             if((nums[s] == nums[mid]) && (nums[e] == nums[mid]))
//             {
//                 s++;
//                 e--;
//             }
//             else if(nums[s]<=nums[mid])
//             {
//                 if(target<nums[mid] && target>=nums[s])
//                     e=mid-1;
//                 else
//                     s=mid+1;
//             }
            
//             else
//             {
//                 if(target>nums[mid] && target<=nums[e])
//                    s=mid+1;
//                 else
//                     e=mid-1;
//             }
            
//         }
//         return false;
//     }
// };

public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), lo = 0, hi = m - 1, mid; 
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int max_row = 0;
            for (int i = 0; i < n; ++i) {
                if (matrix[max_row][mid] < matrix[i][mid])
                    max_row = i;
            }
            if ((mid == 0 || matrix[max_row][mid] > matrix[max_row][mid - 1]) && 
                (mid == m - 1 || matrix[max_row][mid] > matrix[max_row][mid + 1]))
                return {max_row, mid};
            else if (mid > 0 && matrix[max_row][mid - 1] > matrix[max_row][mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return {-1, -1};
    }
};
