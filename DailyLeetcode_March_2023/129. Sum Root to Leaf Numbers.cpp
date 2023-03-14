129. Sum Root to Leaf Numbers 

Code: 

 
class Solution {
public:
    int sumNumbers(TreeNode* root, int sum = 0) {
        if(!root){
            return 0;
        }

        //we multiply the value by 10 so to get the root value.  
        sum = sum*10 + root -> val;
        
        if(!root -> left && !root-> right){
            return sum;
        }

        return sumNumbers(root -> left, sum) + sumNumbers(root -> right, sum);
        
    }
};
