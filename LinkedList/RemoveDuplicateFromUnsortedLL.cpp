//Q - Remove duplicate form unsorted array :  CodeStudio problem 


code1: // using map 
#include<unordered_map>
Node *removeDuplicates(Node *head)
{
    if(head==NULL){
     return NULL;
 }

 unordered_map<int,bool>visited;
   Node* prev = head;
   Node* curr = head->next;
   
   visited[prev->data] = true;
   
   while(curr!=NULL){
       if(visited[curr->data] == true){
           prev->next = curr-> next;
           delete(curr);
       }
       else{
           visited[curr->data] = true;
           prev = prev->next;
       }
       curr = prev->next;
   }
   return head;
}

code2: brutee force 
Node *removeDuplicates(Node *head)
{
   // Write your code here
    map<int,bool> check;
     Node *prev=NULL;
     Node *temp=head;
     
     while(temp!=NULL){
         if(check[temp->data]!=true){
             check[temp->data]=true;
             prev=temp;
             temp=temp->next;
         }
         else{
             prev->next=temp->next;
             Node *todelete=temp;
             temp=temp->next;
             delete todelete;
         }
     }
     return head;
     
}
