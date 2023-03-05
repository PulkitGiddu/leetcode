Binary Tree Representation 
/*
You are given an array nodes. It contains 7 integers, which represents the value of nodes of the binary tree in level order traversal. 
You are also given a root of the tree which has a value equal to nodes[0].
Your task to construct a binary tree by creating nodes for the remaining 6 nodes.
*/

Code:  // Solution using queue. 

class Solution{
public: 
void create_tree(node* root0, vector<int> &vec){
  queue<node*> q;
  q.push(root0);
  
  while( i < n){
    node * root = q.front(); 
    q.pop(); 
    
    node* left = newNode(vec[i++]);
    root -> left = left ;
    q.push(left); 
    
    if(i>= n) break; 
    
    node * right = newNode(vec[i++]);
    root -> right = right; 
    q.push(right); 
    
    }
  }
};
