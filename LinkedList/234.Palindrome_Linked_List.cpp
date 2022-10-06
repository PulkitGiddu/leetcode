// Q - 234. Palindrome Linked List 

/*
first we have to check weather the LL is a paildome or not 
1 -> 2 -> 3 -> 3 -> 2 -> 1
if all the elements form left to right and riight to left is same then LL is paildrome 

Naive approch is : 
Taking all the values and putting that into vector or array and then checking it is paildrome
time compelexity to this appproch is O(n) + O (n) i.e. O(n)
space complexity : O(n)
*/
code :

// class Solution {
// public:
//     ListNode* temp;
//     bool isPalindrome(ListNode* head) {
//         temp = head;
//         return check(head);
//     }
    
//     bool check(ListNode* p) {
//         if (NULL == p) return true;
//         bool isPal = check(p->next) & (temp->val == p->val);
//         temp = temp->next;
//         return isPal;
//     }
// };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        prev = slow, slow = slow->next, prev->next = NULL;
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        fast = head, slow = prev;
        while (slow)
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;
        return true;
    }
};

//T.C = O(n)
//S.C = O(1)
