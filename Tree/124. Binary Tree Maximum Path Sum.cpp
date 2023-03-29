124. Binary Tree Maximum Path Sum 

Code: 

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi); 
        return maxi;  
    }


    int maxPathDown(TreeNode* node, int& maxi){

        if(!node){
            return 0; 
        }

        int left = max(0, maxPathDown(node -> left, maxi));  // if we get negative edge then we simply ignore that coz it will never give us the max sum. that is why 0 is passed between.
        int right = max(0, maxPathDown(node -> right, maxi));  // same here

        maxi = max(maxi , left + right + node -> val); 

        return max(left, right) + node -> val; 


    }
    
};





















