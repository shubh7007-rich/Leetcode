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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> ans;
        int lvl = 0;    
        while(!que.empty()){
            int size = que.size();
            vector<int> temp;

            while(size--){
                auto p = que.front();
                que.pop();

                temp.push_back(p->val);

                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);

            }
            if(lvl&1) reverse(temp.begin() , temp.end());
            ans.push_back(temp);

            lvl++;
        }

        return ans;
    }
};