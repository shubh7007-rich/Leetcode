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
    bool check(TreeNode* t1 , TreeNode* t2){
        if(t1 == NULL && t2 == NULL) return true;

        if(!t1 && t2 || (t1 && !t2)) return false;

        if(t1->val != t2->val) return false;

        return check(t1->left , t2->left) && check(t1->right , t2->right);
    }
    bool preorder(TreeNode* root , TreeNode* subRoot){
        if(root == NULL) return false;

        if(check(root , subRoot)) return true;
        bool left = preorder(root->left , subRoot);
        if(left) return true;
        bool right = preorder(root->right , subRoot);
        if(right) return true;

        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return preorder(root , subRoot);
    }
};