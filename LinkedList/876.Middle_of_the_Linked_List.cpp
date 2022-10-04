Q - 876. Middle of the Linked List : 
/*
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/
Code1: Approch 1: 
class Solution {
private: 
    int getLength(ListNode* head){
      int len = 0;
        while(head != NULL ){
            len++;
            head  = head -> next;
        }
        return len;
    }
  public:
    ListNode* middleNode(ListNode* head) {
      int len = getLength(head);
      int ans = len/2;
      ListNode* temp = head;
      int cnt = 0;
      while(cnt < ans){
      temp = temp -> next;
        cnt++;
      }
      return temp;
    }
};

// T.C -> O(n)
// S.C -> O(n) + O(n/2) = O(N)

Code2: Approch 2 :
class Solution{
  public: 
    ListNode* middleNode(ListNode* head) { 
      if(head == NULL || head -> next == NULL){
      return (head);
      }
      
      ListNode* slow = head; 
      ListNode* fast = head -> next;
      while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
          fast = fast -> next;
        }
      slow = slow -> next;
      }
      return slow;
    }
};

//   T.C = O(n/2) = O(n)
//   S.C = O(1)
