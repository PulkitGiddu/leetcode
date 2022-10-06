// Q - 328. Odd Even Linked List
/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,
and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 
*/

Code : 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      
        /*if(!head || !head->next || !head->next->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head;
        */
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
       
        ListNode* oddtail = head;
        ListNode* oddHead = head;
        ListNode* eventail = head->next;
        ListNode* evenHead = head->next; 
        
        while(eventail != NULL && eventail->next != NULL) {
            oddtail->next = eventail->next;
            oddtail = eventail->next;
            
            eventail->next = oddtail->next;
            eventail = oddtail->next;
        }
        
        oddtail->next = evenHead;
        return oddHead;
    }
};
