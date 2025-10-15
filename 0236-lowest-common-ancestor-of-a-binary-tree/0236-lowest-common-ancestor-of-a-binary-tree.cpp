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
    bool getPath(TreeNode* root, vector<TreeNode*>& path ,  TreeNode* target){
        if(root == NULL) return false;

        path.push_back(root);

        if(root->val == target->val) return true;

        bool left = false , right = false;

      
            right = getPath(root->right , path , target);
        
            left = getPath(root->left , path , target);
        

        if(left || right) return true;

        path.pop_back();

        return false;
    
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 , path2;

        getPath(root , path1 , p);
        getPath(root , path2 , q);

        TreeNode* ans = NULL;

        for(int i = 0 ; i < min(path1.size() , path2.size()) ; i++){
            if(path1[i] == path2[i]){
                ans = path1[i];
            }else{
                break;
            }
        }

        return ans;
    }
};