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
    bool func(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if(root == NULL) return false;
        
        path.push_back(root);

        if(root == target) return true;


        if(func(root->left , target , path)) return true;
        if(func(root->right , target , path)) return true;
        path.pop_back();

        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
            Approach 1 --> get path from root to the nodes and the first node to match we will return

        */

        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        func(root , p , path1);
        func(root , q , path2);
        TreeNode* ans = NULL;
        for(int i = 0 ; i < min(path1.size() , path2.size()) ; i++){
            if(path1[i] == path2[i]){
                ans = path1[i];
            }
        }
        for(auto i : path2){
            cout << i->val << " ";
        }
        return ans;
    }
};