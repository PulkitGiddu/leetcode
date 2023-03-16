106. Construct Binary Tree from Inorder and Postorder Traversal 

Code: 

class Solution{
  public:
  
TreeNode * BuildTree(vector<int>& inorder, vector<int>& postorder){
  if(inorder.size() != postorder.size())
    return NULL; 
  
  // here we store the index of inorder elements to traverse it later.
  map<int, int> hm; // hm = hasmap
  
  for (int i = 0; i<inorder.size(); ++i){
  hm[inorder[i]] = i; 
    
    return buildTreePostIn(inorder, 0 , inorder.size()-1, postorder, 0, postorder.size()-1, hm);
  }
  
  TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& hm){
    // is, ie -> inorder start and inorder end. 
    // ps, pe -> postorder start and postorder end.
    if(ps > pe || is > ie){
      return NULL;
  }
    
    // here in postorder left right root that is the last element we are taking it as root of tree.
    TreeNode* node = new TreeNode(postorder[pe]);
      
    // here we are searching for element present in postorder last index into inorder hashmap index. 
    int inRoot = hm[postorder[pe]];
    
    // apply recursive call to the left of inorder and post order 
    root -> left  = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps, ps + inRoot - is - 1, hm);
    
    // apply recursive call to the right 
    root -> right = buildTreePostIn(inorder, is, inRoot + 1, postorder, ps, ps + inRoot - is, pe - 1, hm);
    
    return root; 
  }
}
