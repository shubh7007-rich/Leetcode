/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
            naive approach --> to get the path from root the nodes p and q and just compare and return the righmost common node in both the paths

            better approach --> 

            optimal approach --> if both nodes are smaller than the current node go to the left and both nodes are greater go the right , else return root (when either one is greater than the root and another one is smaller)

        */

        // if(root == NULL) return NULL;
        
        // TreeNode* ans = NULL;

        // if(root->val > p->val && root->val > q->val){
        //     ans = lowestCommonAncestor(root->left , p , q);
        // }else if(root->val < p->val && root->val < q->val){
        //     ans = lowestCommonAncestor(root->right , p , q);
        // }else{
        //     ans = root;
        // }

        // return ans;   

        while(root){
            if(root->val > p->val && root->val > q->val){
                root = root->left;
        }else if(root->val < p->val && root->val < q->val){
            root = root->right;
        }else{
            return root;
        }
        }

        return NULL;
    }
};