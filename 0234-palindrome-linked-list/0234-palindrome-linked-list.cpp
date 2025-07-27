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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head , *fast = head , *p = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL , *nxt = slow->next;

        while(slow){
            nxt = slow->next;

            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        while(p && prev){
            if(p->val != prev->val) return false;

            p = p->next;
            prev = prev->next;
        }

        return true;
    }
};