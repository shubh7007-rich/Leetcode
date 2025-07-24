class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();

        /*
    -> rotating by 90* is just taking every row and placing it vertically from the last -> first column
    -> so if we look closely , if we want to rotate our matrix by 90 degree then we just tranpose our matrix and reverse every row.
    -> this will not require an extra space
         */

         // tranposing our matrix

         for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < m ; j++){
                swap(mat[i][j] , mat[j][i]);
            }
         }

         for(vector<int>& vec : mat){
            reverse(vec.begin() , vec.end());
         }

    }
};