958. Check Completeness of a Binary Tree 

Code: 

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        if(!root)
        return true;

        queue<TreeNode* > q; 

        q.push(root); 
        
        bool fun = 0; 
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            if(front -> left){
                if(fun)
                return false;

                q.push(front -> left);
            }
            else
            fun = 1;
            if(front -> right){
                if(fun)
                return false;

                q.push(front -> right);
            }
            else
            fun = 1;
        }
        return true;
    }
};
