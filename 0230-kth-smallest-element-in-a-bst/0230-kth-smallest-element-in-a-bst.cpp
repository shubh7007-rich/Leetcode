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
    int cnt = 0 ;
    int inorder(TreeNode* node , int k){
        if(node == NULL) return -1;
        int left = inorder(node->left  , k);
        if( left != -1) return left;
        cnt++;
        if(cnt == k) return node->val;
        // ans.push_back(node->val);
        int right = inorder(node->right , k);
        if(right != -1) return right;

        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        /*
            Brute force approach or naive approach -- just do any traversal to traverse the whole tree and store the values in the tree and just sort and return the k-1 value

            better approach --> just do the inorder traversal and store the values in an array and return the k-1 approach

            Even better approach --> as we just the particular value so instead of doing the whole traversal and store the whole bst in an array , just take a cnt and do cnt++ everytime u visit a node and as we reach cnt == k , return that node

        */
        // vector<int> ans;

        return inorder(root , k);

        // return ans[k-1];
    }
};