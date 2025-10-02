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
    // void func(TreeNode* root , vector<int>& ans){
    //     if(root == NULL) return;

    //     ans.push_back(root->val);
    //     func(root->left , ans);
    //     func(root->right , ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // root left right
        vector<int> ans;

        /*
            Morris traversal --> Preorder , Inorder 

            Preorder Traversal --> We will start from the root , and whenever i reach a node that is not null , i will push it into my stack (as well as in my ans array) and move towards the left and when i reach node that is null , i will pop the top of the stack and move towards the right of the node that has been popped

        */

        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if(node != NULL){
                st.push(node);
                ans.push_back(node->val);
                node = node->left;
            }else{
                if(st.empty()) break;

                TreeNode* t = st.top();
                st.pop();

                node = t->right;
            }

        }

        return ans;
    }
};