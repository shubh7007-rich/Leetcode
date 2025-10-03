/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parent){
        if(root == NULL) return;

        if(root->left) parent[root->left] = root;
        preorder(root->left , parent);
        if(root->right) parent[root->right] = root;
        preorder(root->right , parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent;
        // parent[root] = -1;

        vector<int> ans;

        preorder(root , parent);
        int lvl = 0;
        queue<TreeNode*> que;

        que.push(target);

        unordered_set<TreeNode*> vis;

        vis.insert(target);

        while(!que.empty()){
            int size = que.size();
            while(size--){
                auto frontNode = que.front();
                que.pop();

                if(lvl == k){
                    ans.push_back(frontNode->val);
                }

                if(parent.count(frontNode)){
                    auto par = parent[frontNode];
                    if(!vis.count(par)){
                        que.push(par);
                        vis.insert(par);
                    }
                }

                if(frontNode->left && !vis.count(frontNode->left)){
                    que.push(frontNode->left);
                    vis.insert(frontNode->left);
                }
                if(frontNode->right && !vis.count(frontNode->right)){
                    que.push(frontNode->right);
                    vis.insert(frontNode->right);
                }
            }
            lvl++;

            if(lvl > k) break;
        }
        return ans;
    }
};