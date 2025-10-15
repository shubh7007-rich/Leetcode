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
    TreeNode* func(vector<int>& preorder,int preStart , int preEnd , vector<int>& inorder , int inStart , int inEnd , unordered_map<int ,int>& mp){

        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = func(preorder , preStart + 1 , preStart + numsLeft , inorder , inStart , inRoot-1 , mp);
        root->right = func(preorder , preStart + numsLeft + 1 , preEnd , inorder , inRoot + 1 , inEnd , mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*

            preorder --> [3 , 9 , 20 , 15 , 7]

                          0   1   2    3    4
            inorder -->  [9 , 3 , 15 , 20 , 7] 

            next --> 

            left subtree --> preorder -> [9] inorder ->[9]  
            right subtree --> preorder -> [20 15 7] inorder ->[15 20 7]


        */

        unordered_map<int , int> mp;

        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i;
        }

        return func(preorder , 0 , preorder.size() - 1 , inorder , 0 , inorder.size() - 1 , mp);

    }
};