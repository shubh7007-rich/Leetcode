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
        if(!root) return {};
        
        vector<vector<int>> ans;

        queue<TreeNode*> que;
        que.push(root);
        int f = 0;
        while(!que.empty()){
            int size = que.size();
            vector<int> temp(size);
            int ind = 0;
            if(f){
                ind = size-1;
            }else{
                ind = 0;
            }
            while(size--){
                auto p = que.front();
                que.pop();
                temp[ind] = p->val;
                if(f){
                    ind--;
                }else{
                    ind++;
                }

                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
            }
            f = !f;
            ans.push_back(temp);
        }

        return ans;
    }
};