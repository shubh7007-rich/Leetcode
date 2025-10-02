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
        if(!root) return {};
        
        queue<TreeNode*> que;
        int lvl = 0 , l = -1;
        que.push(root);
        vector<int> ans;

        while(!que.empty()){
            int size = que.size();

            while(size--){
                auto fro = que.front();
                que.pop();

                if(l < lvl){
                    ans.push_back(fro->val);
                    l++;
                }

                if(fro->right) que.push(fro->right);
                if(fro->left) que.push(fro->left);
            }

            lvl++;
        }

        return ans;
    }
};