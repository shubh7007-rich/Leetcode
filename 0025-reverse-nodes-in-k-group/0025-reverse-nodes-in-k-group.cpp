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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head;

        while(p){
            ListNode* q = p , *r = p;
            vector<int> temp;
            int cnt = 1 , c = 1;
            while(q && cnt <= k){
                temp.push_back(q->val);
                q = q->next;
                cnt++;
            }
            if(cnt <= k) break;   // there are not k nodes , so i don't have to reverse 

            while(r && c <= k && !temp.empty()){
                r->val = temp.back();
                temp.pop_back();
                c++;
                r = r->next;
            }

            p = q;

        }

        return head;
    }
};