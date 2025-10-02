/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> st;

        vector<int> ans;
        st.push(root);

        while(!st.empty()){
            auto p = st.top();
            ans.push_back(p->val);
            st.pop();

            if(p->left) st.push(p->left);
            if(p->right) st.push(p->right);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
}; 