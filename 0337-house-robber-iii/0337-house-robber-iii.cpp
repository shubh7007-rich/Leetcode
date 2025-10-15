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
    map<pair<TreeNode* , int> , int> dp;

    int func(TreeNode* root , int f){
        if(root == NULL) return 0;

        int take = 0 , notTake = 0;

        if(dp.count({root , f})) return dp[{root , f}];

        if(f){
            take += root->val + func(root->left , 0) + func(root->right , 0);
        }
        notTake += func(root->left , 1) + func(root->right , 1);

        return dp[{root , f}] = max(take , notTake);
    }
    int rob(TreeNode* root) {
        return  func(root , 1);   
    }
};