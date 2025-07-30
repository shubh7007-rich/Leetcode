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
    bool solve(TreeNode* p , TreeNode* q){
        if(p == NULL && q == NULL) return true;

        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false;

        if(!solve(p->left , q->right) || !solve(p->right , q->left)){
            return false;
        }

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true;

        if(root->left == NULL || root->right == NULL) return false;

        TreeNode* p = root->left , *q = root->right;

        return solve(p , q);
    }
};