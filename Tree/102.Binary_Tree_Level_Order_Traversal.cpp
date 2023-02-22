102. Binary Tree Level Order Traversal 

Code: 
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // default data structure that will store the level vise traversal

        // now we need to store the ans for that
        vector<vector<int>> ans; 

        if(root == NULL)
        return ans;

// In this queue store the elements and then check for the left and right of the element 
        queue<TreeNode*> q; 

        q.push(root); 

        while(!q.empty()){
            int size = q.size(); 
            vector<int> level; 

            for(int i = 0; i<size; i++){
                TreeNode* node = q.front(); 
                q.pop(); 

                if(node -> left != NULL) q.push(node -> left); 
                if(node -> right != NULL) q.push(node -> right); 
                level.push_back(node -> val); 
            }
            ans.push_back(level); 
        }
        return ans;
    }
};
