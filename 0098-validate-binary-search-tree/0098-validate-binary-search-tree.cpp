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
 #define ll long long
class Solution {
public:
    bool func(TreeNode* root, ll mini , ll maxi){
        if(root == NULL) return true;

        if(root->val >= maxi || root->val <= mini) return false;

        if(!func(root->left , mini , root->val)) return false;
        if(!func(root->right , root->val, maxi)) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        /*
            Approaches -

            My intial thought process was to just check parent and its two children , if they good then move towaards the left and right towards the whole tree , but this won't work because like for example we have a tree like ->
                                5
                            /       \
                        1              7
                    /               /     \
                0                4          8

        this will satisfy the whole condition but won't work becaue 4 needs to be greater than 4 and 7
        so every number needs to be in a specific range for bst to be valid

        so like every node needs to be between a certain range

            Brute Approach --> Just find the inorder traversal and if it is increasing then it is bst else not
            
            Optimal Approach --> every node needs to be in a specific range so we will start from the root node and it needs to be in the range [LLONG_MIN , LLONG_MAX]  as every needs to be in between of the range i.e both the end points are exclusive and element values can be INT_MIN , INT_MAX so we need to use LLONG_MIN , LLONG_MAX , when we are moving left from root node then our range will boil down to [LLONG_MIN , root->val] and when we going right then [root->val , LLONG_MAX] and then similarly for all the nodes

        */

        return func(root , LLONG_MIN , LLONG_MAX);
    }
};