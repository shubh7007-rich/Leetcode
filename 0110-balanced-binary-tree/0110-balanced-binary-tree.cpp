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
    /*
        height balanced binary tree is the one in which the difference between the height of two subtrees does not differ by one

        brute force approach would be to go at every node using any traversal and calculate the height of left and right subtree using the maxDepth function and if it differs more than 1 than return false

        So when we wrote the maxDepth function to find the height of the binary tree in each recursive call we were calculating height of the left and right subtree , so we can just check for this balance condition in every recursive if gets violated at any step we can just return false

    */

    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;

        int left = maxDepth(root->left);
        if(left == -1) return -1;
        int right = maxDepth(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;

        return 1 + max(left , right);
    }
    bool isBalanced(TreeNode* root) {
        // if(root == NULL) return true;

        // if(!isBalanced(root->left)) return false;
        // if(!isBalanced(root->right)) return false;

        // int left = maxDepth(root->left);
        // int right = maxDepth(root->right);

        // if(abs(left - right) > 1) return false;

        return (maxDepth(root) == -1) ? false : true;
    }
};