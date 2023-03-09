142. Linked List Cycle II 

Code:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) // if there is empty list or only one node is there return NULL;
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;             // Moving slow by one position 
            fast = fast->next->next;       // Fast by 2 positions 
            if(slow == fast){              // there is a cycle 
                while(slow != entry){      // found the entry location.
                slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;                      // there has no cycle
    }
};
