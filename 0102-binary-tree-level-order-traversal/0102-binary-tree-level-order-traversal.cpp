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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return {};
        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<int> temp;
            while(size--){
                auto fro = que.front();
                que.pop();

                temp.push_back(fro->val);

                if(fro->left) que.push(fro->left);
                if(fro->right) que.push(fro->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};