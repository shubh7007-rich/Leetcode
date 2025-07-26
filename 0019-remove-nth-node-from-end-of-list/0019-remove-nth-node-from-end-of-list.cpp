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
        int len = 0;
        ListNode* p = head;

        while(p != NULL){
            len++;
            p = p->next;
        }

        int t = len - n;
        ListNode* q = head;
        ListNode* r = q->next;

        if(t == 0){
            head->next = NULL;
            return r;
        }

        while(t > 1){
            q = q->next;
            r = r->next;
            t--;
        }

        q->next = r->next;
        r->next = NULL;

        return head;
    }
};