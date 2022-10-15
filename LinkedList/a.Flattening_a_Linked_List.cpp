Q -Flattening a Linked List

code: 
//C++ sol. with O(1) space complexity

//merge two sorted list in sorted order
Node* merge(Node* first, Node* second){
if(first == NULL)
  return second;
  if(second == NULL)
    return first;
  
  // Check for the bottom list in first pointer 
  if(first -> bottom == NULL){
  first -> bottom = second;
    return first;
  }
  
  // Creting 3 pointer 
  Node* curr1 = first;
  Node* curr2 = second;
  Node* forward = curr1 -> bottom;
  
  while(forward != NULL && curr2!= NULL){
  if((curr1 -> data <= curr2 -> data) && (forward -> data >= curr2 -> data)){
     curr1 -> bottom = curr2; 
     Node* temp = curr2 -> bottom;
     curr2 -> bottom = forward; 
     curr1 = curr2; 
     curr2 = temp;
  }
    else{
          curr1 = forward; 
          forward = forward -> bottom;
    }
  }
  if(forward == NULL)
    curr1 -> bottom = curr2; 
    return first; 
}

Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL)
     return NULL;
     
     //divide in down and right
     Node *down=root;
     Node *right=root->next;
     down->next=NULL;
     
     //to get right list in sorted order using Recursion
     right=flatten(right);
     
     //merge down and right list
     return merge(down,right);
}

// T.C = O(N)
// S.C = O(1)
