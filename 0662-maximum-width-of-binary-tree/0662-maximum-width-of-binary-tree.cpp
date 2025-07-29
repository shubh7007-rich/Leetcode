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
        if(root == NULL) return 0;

        long long maxWidth = 1;

        queue<pair<TreeNode* , int>> que;               // Node and Index

        que.push({root , 0});

        while(!que.empty()){
            int size = que.size();
            long long firstIdx = -1 , lastIndex = 0;
            while(size--){
                auto p = que.front();
                que.pop();

                TreeNode* node = p.first;
                long long index = p.second;

                if(firstIdx == -1) firstIdx = index;
                lastIndex = index;

                if(node->left) que.push({node->left , 2*index + 1});
                if(node->right) que.push({node->right , 2*index + 2});
            }

            maxWidth = max(maxWidth , lastIndex - firstIdx + 1);
        }

        return maxWidth;
    }
};