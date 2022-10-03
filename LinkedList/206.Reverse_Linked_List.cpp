// Q - 206. Reverse Linked List
/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
*/
Code2: 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
         
        ListNode* forward = NULL;
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};

// TC: O(n)
// SC : O(1)


code2:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};
