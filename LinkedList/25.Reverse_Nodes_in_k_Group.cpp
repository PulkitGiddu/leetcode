//Q - 25. Reverse Nodes in k-Group 
/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/
code:
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        for(int i=0; i<k; i++){
            if(!curr) return head;
            curr = curr -> next;
        }
        
        curr = head;
        for(int i = 0; i < k; i++){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        if(next != NULL)
        head -> next = reverseKGroup(next, k);
        return prev;
    }
};
