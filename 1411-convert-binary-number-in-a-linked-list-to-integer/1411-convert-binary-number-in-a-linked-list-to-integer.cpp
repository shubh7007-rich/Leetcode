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
    int getDecimalValue(ListNode* head) {
        vector<int> arr;

        while(head){
            arr.push_back(head->val);
            head = head->next;
        }

        int p = arr.size()-1 , ans = 0 , a = 1;

        while(p >= 0){
            if(arr[p]){
                ans += a;
            }
            a *= 2;
            p--;
        }

        return ans;

    }
};