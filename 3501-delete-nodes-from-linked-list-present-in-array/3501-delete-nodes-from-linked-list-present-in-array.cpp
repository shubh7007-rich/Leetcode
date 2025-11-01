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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin() , nums.end());

        ListNode* dummy = head;

        while(dummy != NULL){
            if(st.count(dummy->val)){
                dummy = dummy->next;
            }else{
                break;
            }
        }

        ListNode* ptr = dummy->next , *prev = dummy;

        while(ptr){
            if(st.count(ptr->val)){
                prev->next = ptr->next;
            }else{
                prev = prev->next;
            }
            ptr = ptr->next;
        }
        return dummy;
    }
};