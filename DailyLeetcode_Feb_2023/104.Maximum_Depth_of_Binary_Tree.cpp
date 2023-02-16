104. Maximum Depth of Binary Tree 

Code: 

class Solution{
    public: 
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0; 
        }
        int left = maxDepth(root -> left); 
        int right = maxDepth(root -> right) ; 
        return max(left, right) + 1;
    }
}; 

