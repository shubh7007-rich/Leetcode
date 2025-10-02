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
    int maxi = INT_MIN;

    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        maxi = max({maxi , left + right + root->val , root->val , left + root->val , right + root->val});

        return root->val + max({left , right , 0});
    }
    int maxPathSum(TreeNode* root) {
        maxDepth(root);

        return maxi;
    }
};