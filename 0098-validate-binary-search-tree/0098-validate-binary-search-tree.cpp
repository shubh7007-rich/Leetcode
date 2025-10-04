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
 #define ll long long
class Solution {
public:
    bool func(TreeNode* root , ll mini , ll maxi){
        if(root == NULL) return true;

        if(root->val <= mini || root->val >= maxi) return false;

        if(!func(root->left , mini , root->val)) return false;
        if(!func(root->right , root->val , maxi)) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {

        return func(root , LLONG_MIN , LLONG_MAX);
    }
};