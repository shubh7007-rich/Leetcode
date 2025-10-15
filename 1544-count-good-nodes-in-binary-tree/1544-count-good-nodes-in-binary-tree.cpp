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
    int func(TreeNode* root , int maxi , int & cnt){
        if(root == NULL) return 0;

        int c = 0 , total = 0;

        if(root->val >= maxi){
            c = 1;
        } 

        maxi = max(maxi , root->val);

        total += c + func(root->left , maxi , cnt) + func(root->right , maxi , cnt);
        
        return total;
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;

        return func(root , INT_MIN , cnt);

        // return cnt;
    }
};