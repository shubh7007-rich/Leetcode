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
    TreeNode* func(TreeNode* root , int target){
        if(root == NULL) return NULL;

        root->left = func(root->left , target);
        root->right = func(root->right , target);

        if(root->left == NULL && root->right == NULL && root->val == target) return NULL;

        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;

        root = func(root , target);

        /*
            we are using dfs traversal to solve this , so which one ?

            preorder doesn't make sense because why would we consider deleting a node before processing the left and right subtree 
            for ex -> 

                        1      target = 2
                       /
                      2 ------> why would we consider deleting this node before other 
                     /          nodes
                    2
                   / \
                  2   3

                same for inorder

                        1      target = 2
                       /
                      2 ------> why would we consider deleting this node before other 
                     /          nodes
                    2
                     \
                      3
                     /
                    2
        */

        return root;
    }
};