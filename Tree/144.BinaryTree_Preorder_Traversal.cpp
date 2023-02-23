144. Binary Tree Preorder Traversal 

Code: 


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root == NULL) return preOrder;

        stack<TreeNode*> st; 
        st.push(root); 

        while(!st.empty()){
            root = st.top(); 
            st.pop(); 

            preOrder.push_back(root -> val); 
            if(root -> right != NULL){
                st.push(root -> right); 
            }
            if(root -> left != NULL){
                st.push(root -> left);
            }
        }
        return preOrder; 
    }
};
