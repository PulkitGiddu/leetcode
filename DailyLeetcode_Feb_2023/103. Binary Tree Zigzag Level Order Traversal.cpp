103. Binary Tree Zigzag Level Order Traversal 

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == NULL) 
        return ans; 

        q.push(root); 
        int flag = 0; // flag variable tell us left to right if zero

        while(q.size()){

            vector<int> temp; 

            int si = q.size(); // si denotes the size of queue
            
            while(si--){
                TreeNode* te = q.front(); //te denotes the front element in the queue 
                q.pop();

                if(te -> left != NULL){
                    q.push(te -> left);
                }
                if(te -> right != NULL){
                    q.push(te -> right);
                }
                temp.push_back(te -> val); 
            }
            if(flag == 0){
                flag = 1; // make flag to 1 
                ans.push_back(temp);  
            }
            else{
                reverse(temp.begin(), temp.end()); 
                ans.push_back(temp);

                // make the flag equal to zero
                flag = 0;  
            }
        }
        return ans;
    }
};
