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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> ans;
        if(root == NULL) return {};
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            int value = 0;
            while(size--){
                auto fro = que.front();
                que.pop();
                value = fro->val;
                if(fro->left) que.push(fro->left);
                if(fro->right) que.push(fro->right);
            }
            ans.push_back(value);
        }

        return ans;
    }
};