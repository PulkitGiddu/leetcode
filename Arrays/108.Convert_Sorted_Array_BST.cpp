// 108. Convert Sorted Array to Binary Search Tree

// we can solve this by recurrsion 
// let's say 
//   [-], -3, -0, 5, 9]
//    L        0     r     // left, right, root node
/*

*/

code: 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* convertBST(int left,int right,vector<int>&arr){
//         if(left>right) return nullptr;
//         int mid = left+((right-left)/2);
//         TreeNode * root = new TreeNode(arr[mid]);
//         root->left = convertBST(left,mid-1,arr);
//         root->right = convertBST(mid+1,right,arr);
//         return root;
//     }
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         return convertBST(0,nums.size()-1,nums);
//     }
// };
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int low,int high){
        if(low<=high){
            int mid = low + (high-low)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = helper(nums, low, mid-1);
            root->right = helper(nums, mid+1, high);
            return root;
        }
        return NULL;
    }
};
