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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA , *p2 = headB;
        int len1 = 0 , len2 = 0;
        while(p1){
            p1 = p1->next;
            len1++;
        }
        while(p2){
            p2 = p2->next;
            len2++;
        }

        int diff = abs(len1 - len2);

        if(len1 > len2){
            while(diff--) headA = headA->next;
        }else{
            while(diff--) headB = headB->next;
        }

        while(headA && headB){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};