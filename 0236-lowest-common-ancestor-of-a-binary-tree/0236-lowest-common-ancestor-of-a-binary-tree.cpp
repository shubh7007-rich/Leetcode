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
    /*

    Approach 2 -> T.C - O(n) , S.C - O(1)
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;

        if(root == p || root == q) return root;

        TreeNode * left = solve(root->left , p , q);
        TreeNode * right = solve(root->right , p , q);

        if(left && right) return root;

        if(left != NULL) return left;

        return right;
    }
    */
    bool getPath(TreeNode* root, TreeNode* target , vector<TreeNode*> &vec){
        if(root == NULL) return false;

        vec.push_back(root);
        
        if(root == target) return true;

        if(getPath(root->left , target , vec)){
            return true;
        }

        if(getPath(root->right , target , vec)){
            return true;
        }

        vec.pop_back();

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return solve(root , p , q);

        //     Appraoch 1 -> We can store paths to both of the nodes and store
        //     them in a vector and then traverse both of the vectors
        //     simultaneously and return the first common node
        // T.C - O(N) , S.C - O(n)

        vector<TreeNode*> pathQ, pathP;
        TreeNode *ans = NULL;

        if(root == p || root == q) return root;

        getPath(root, p, pathP);
        getPath(root, q, pathQ);

        int len = min(pathP.size() , pathQ.size());

        for(int i = 0 ; i < len ; i++){
            if(pathQ[i] == pathP[i]) ans = pathQ[i];
        }

        return ans;
    }
};