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
    bool func(TreeNode* a , TreeNode* b){

        if(a && !b || !a && b) return false;

        if(a == NULL && b == NULL) return true;
        
        if(a->val != b->val) return false;

        bool left = func(a->left , b->right);
        if(!left) return false;
        bool right = func(a->right , b->left);
        if(!right) return false;

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return func(root->left , root->right);
    }
};