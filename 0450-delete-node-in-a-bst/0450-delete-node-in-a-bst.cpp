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
    TreeNode* rightt(TreeNode* root){
        if(root->right == NULL) return root;

        return rightt(root->right);
    }

    TreeNode* helper(TreeNode* root){
        if(root->right == NULL) return root->left;
        if(root->left == NULL) return root->right;

        TreeNode* dummy = root;

        TreeNode* rightMost = rightt(dummy->left);

        rightMost->right = dummy->right;

        return dummy->left;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

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

/*

                        7
                       / \
                      5   9
                     / \  /\
                    3   6 8 11
                   / \
                  1   4


                        7
                       / \
                      3   9
                     / \  /\
                    1   4 8 11
                         \
                          6

we will find that particular node , and delete it 
                

*/