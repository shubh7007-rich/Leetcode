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
            vector<int> temp(size);
            int i = 0;
            if(lvl&1) i = size - 1;
            while(size--){
                auto p = que.front();
                que.pop();
                temp[i] = p->val;
                if(lvl&1){
                    i--;
                }else{
                    i++;
                }

                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
            }
            ans.push_back(temp);

            lvl++;
        }

        return ans;
    }
};