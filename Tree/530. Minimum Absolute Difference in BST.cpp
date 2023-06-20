530. Minimum Absolute Difference in BST
// using inorder traversal 


class Solution {
public:
    TreeNode* prev = NULL; 
    void solve(TreeNode* root, int& ans){
        if(root -> left){
            solve(root -> left, ans); 
        }
        if(prev!= NULL){
            ans = min(ans , abs(prev -> val - root -> val));
        }
        prev = root;
        if(root -> right){
            solve(root -> right, ans);
        }
    }
    int getMinimumDifference(TreeNode* root) {
      int ans = INT_MAX; 
      solve(root , ans); 
      return ans; 
    }
};
