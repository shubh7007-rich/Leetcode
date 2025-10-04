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
    TreeNode* buildTree(int& ind , vector<int>& preorder , int mini , int maxi){
        if(ind >= preorder.size() || preorder[ind] > maxi) return NULL;

        TreeNode* root = new TreeNode(preorder[ind++]);

        root->left = buildTree(ind , preorder , mini , root->val);
        root->right = buildTree(ind , preorder , mini , maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        /*
            we need to construct a bst whose preorder traversal will be preorder (the given array)

            now preorder is ROOT LEFT RIGHT and as we need to construct bst , we will take the first value in preorder as root and the next consecutive values (all smaller than the root) will be in the left subtree and other consecutive values greater than the root will be in the right subtree 

            so how can we do it ? we know that every value in a bst will be in a particular range

            so starting of with range [INT_MIN , INT_MAX]

            ex - [8,5,1,7,10,12]

            as 8 is in the range [INT_MIN , INT_MAX] we will take it 

                                    8
            now we will move forward to the left first and change the range to [INT_MIN , 8] and move to the pointer to 5
            Now is 5 in the range [INT_MIN , 8] ? yes it is , so we will make a node to the left of 8 and move towards the left and move the pointer to the next element and change the range to [INT_MIN , 5]

           Now is 1 in the range [INT_MIN , 5] ? yes it is , so we will make a node to the left of 5 and move towards the left and move the pointer to the next element and change the range to [INT_MIN , 1]

           now the pointer is pointing to 7 , now is 7 in the range [INT_MIN , 1] ? no its not so we will make the left of 1 NULL and move to the right of 1 ,(MOST IMP) AND WHILE MOVING TO THE RIGHT OF 1 WE WILL KEEP THE RANGE AS [INT_MIN , 5] , and check is 7 in the range [INT_MIN , 5] ? no , so we will make the right of 1 null and then traverse back to node 5

           as we explored the left of 5 , now we will go to the right of 5 with the range [INT_MIN , 8] , now is 7 in the range [INT_MIN , 8] ? yes so insert it

        */
        int ind = 0;
       return buildTree(ind , preorder , INT_MIN , INT_MAX);

    }
};