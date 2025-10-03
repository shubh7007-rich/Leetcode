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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode* , int>> que;  // node , index

        que.push({root , 0});
        int maxi = 0;

        while(!que.empty()){
            int leftmost = -1 , rightmost = -1;
            int size = que.size();
            int minIndex = que.front().second;
            while(size--){
                auto p = que.front();
                TreeNode* node = p.first;
                int index = p.second - minIndex;
                que.pop();

                if(leftmost == -1) leftmost = index;
                rightmost = index;

                if(node->left) que.push({node->left , 2*1ll *index + 1});
                if(node->right) que.push({node->right , 2* 1ll *index + 2});
            }

            maxi = max(maxi , rightmost - leftmost + 1);
        }

        return maxi;
    }
};