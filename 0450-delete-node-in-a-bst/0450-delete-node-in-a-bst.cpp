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
    TreeNode* rightt(TreeNode* node){
        if(node->right == NULL) return node;

        return rightt(node->right);
    }
    TreeNode* helper(TreeNode* node){
        if (node->right == NULL) return node->left;
        if (node->left == NULL) return node->right;

        TreeNode* dummy = node;
        TreeNode* rightMost = rightt(node->left);
        rightMost->right = node->right;

        return dummy->left;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(root->val == key){
            return helper(root);
        }

        TreeNode* dummy = root;

        while(root != NULL){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};