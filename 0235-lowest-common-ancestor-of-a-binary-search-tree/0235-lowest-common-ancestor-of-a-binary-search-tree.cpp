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
    bool getPath(TreeNode* root , TreeNode* target , vector<TreeNode*>& path){
        if(root == NULL) return false;

        path.push_back(root);

        if(root == target) return true;

        bool ans = false;

        if(root->val > target->val){
            ans = getPath(root->left , target , path);
        }else{
            ans = getPath(root->right , target , path);
        }

        if(ans) return true;

        path.pop_back();

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
            Brute Force approach --> just calculate the path from the root node to p and to q , and take the rightmost common node

        */

        // coding the brute force approach
        vector<TreeNode*> path1 ,path2;

        getPath(root , p , path1);
        getPath(root , q , path2);

        TreeNode* ans = NULL;

        for(int i = 0 ; i < min(path1.size() , path2.size()) ; i++){
            if(path1[i] == path2[i]){
                ans = path1[i];
            }
        }

        return ans;
    }
};