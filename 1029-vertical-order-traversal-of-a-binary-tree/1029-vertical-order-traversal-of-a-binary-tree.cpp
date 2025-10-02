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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        map<int , map<int , multiset<int>>> mp;

        queue<pair<TreeNode* , int>> que;

        que.push({root , 0});
        int lvl = 0;

        while(!que.empty()){
            int size = que.size();

            while(size--){
                auto p = que.front();
                TreeNode* node = p.first;
                int line = p.second;
                mp[line][lvl].insert(node->val);

                que.pop();

                if(node->left) que.push({node->left , line - 1});
                if(node->right) que.push({node->right , line + 1});
            }
            lvl++;
        }

        for(auto [mp1 , mp2] : mp){
            vector<int> temp;
            for(auto [level , values] : mp2){
                for(int val : values){
                    temp.push_back(val);
                }
            } 
            ans.push_back(temp);
        }

        return ans;
    }
};