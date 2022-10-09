// Q -148. Sort List

Code: 
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node* sortList(Node *head)
{
        int zeroCount = 0;     
        int oneCount = 0;        
        int twoCount = 0;
        
        Node* temp = head;
      

        while(temp != NULL){
            if(temp -> data == 0)
                zeroCount++;
            else if( temp -> data == 1)
                oneCount++;
            else if(temp -> data == 2)
                twoCount++;
            
            temp = temp -> next;
        }
        temp = head;
        
  while(temp != NULL){
            if(zeroCount != NULL){
                temp -> data = 0;
                zeroCount--;
            }
            else if(oneCount != 0){
                temp -> data = 1;
                oneCount--; 
            }
            else if(twoCount != 0){
                temp -> data = 2;
                twoCount--;
            }
            temp = temp -> next;
        }
        return head;
    }
 
// T.C = O(N)
// S.C = O(1)

Code2: 
void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}


Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

//Leetcode Solutions
/*
class Solution{
    public: 
ListNode* sortList(ListNode* head){
    bool done = (!head);
    // Keep partitioning our list into bigger sublists length. Starting with a size of 1 and doubling each time
    for (int step = 1; !done; step *= 2) {
      done = true;
      ListNode** next_ptr = &head;
      ListNode* remaining = head;
      ListNode* list[2];
      do {
        // Split off two sublists of size step
        for (auto& sub_head : list) {
          sub_head = remaining;
          ListNode* tail = nullptr;
          for (int i = 0; i < step && remaining; ++i, remaining = remaining->next) {
            tail = remaining;
          }
          // Terminate our sublist
          if (tail) {
            tail->next = nullptr;
          }
        }

        // We're done if these are the first two sublists in this pass and they
        // encompass the entire primary list
        done &= !remaining;

        // If we have two sublists, merge them into one
        if (list[1]) {
          while (list[0] || list[1]) {
            int idx = (!list[1] || list[0] && list[0]->val <= list[1]->val) ? 0 : 1;
            *next_ptr = list[idx];
            list[idx] = list[idx]->next;
            next_ptr = &(**next_ptr).next;
          }

          // Terminate our new sublist
          *next_ptr = nullptr;
        } else {
          // Only a single sublist, no need to merge, just attach to the end
          *next_ptr = list[0];
        }
      } while (remaining);
    }
    return head;
  }
};



class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //If List Contain a Single or 0 Node
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
            
    }
    
    //MergeSort Function O(n*logn)
    ListNode* mergelist(ListNode *l1, ListNode *l2)
    {
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        
        curr = curr ->next;
        
        }
        
        //for unqual length linked list
        
        if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }
};
*/
