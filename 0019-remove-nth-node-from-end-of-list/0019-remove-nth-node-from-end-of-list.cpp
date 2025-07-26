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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* 
            So basically what we can do here is we can take two pointers slow and fast .And then give   fast a head start of n and then move both the pointers one by one until fast->next == NULL . Slow will be behind the node that has to be deleted.

            Proof - lets take length of the linked as 6 and n = 2, so now that mean we need to delete
            5th node from the start , so slow needs to be on the 4th node. 


            1stNode   2ndNode   3rdNode    4thNode     5thNode    6thNode
    1st step                      fast
    2nd step slow                 fast
    3rd step                                slow                    fast

        */

        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 1; i <= n ; i++) fast = fast->next;

        if(!fast) return head->next;

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }


        slow->next = slow->next->next;
        
        return head;
    }
};