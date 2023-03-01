912. Sort an Array 
Code: 
// If the array contains only one element or less, it is already sorted, so return.
// Divide the array into two halves, by finding the middle index.
// Recursively sort the left and right halves by calling Merge Sort on them.
// Merge the sorted left and right halves by creating a temporary array to hold the merged result.
// Initialize three indices i, j, and k to 0, mid+1, and 0 respectively.
// While i is less than or equal to mid and j is less than or equal to right:
// If nums[i] is less than or equal to nums[j], add nums[i] to temp[k], and increment i and k.
// Otherwise, add nums[j] to temp[k], and increment j and k.
// While i is less than or equal to mid:
// Add nums[i] to temp[k], and increment i and k.
// While j is less than or equal to right:
// Add nums[j] to temp[k], and increment j and k.
// Copy the elements of the temporary array back into the original array nums, starting at index left.
// Return the sorted array.

class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int p = 0; p < k; p++) {
            nums[left + p] = temp[p];
        }
    }
    
    void merge_sort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        merge_sort(nums, left, mid);
        merge_sort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};
