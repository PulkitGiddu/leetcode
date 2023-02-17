783. Minimum_Distance_Between_BST_Nodes

Code: 

class Solution {
 public:
  int minDiffInBST(TreeNode* root) {
    int ans = INT_MAX;
    inorder(root, ans);
    return ans;
  }

 private:
  int pred = -1;

  void inorder(TreeNode* root, int& ans) {
    if (root == nullptr)
      return;

    inorder(root->left, ans);
    if (pred >= 0)
      ans = min(ans, root->val - pred);
    pred = root->val;
    inorder(root->right, ans);
  }
};

Code: 

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        if(root->left) inorder(root->left,v);
        v.push_back(root->val);
        if(root->right) inorder(root->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
     
        int mindiff = INT_MAX;
        for(int i=1;i<v.size();i++){
            if(v[i]==NULL) continue;
            int diff = abs(v[i]-v[i-1]);
            mindiff = min(mindiff,diff);
        }
        return mindiff;
    }
};
