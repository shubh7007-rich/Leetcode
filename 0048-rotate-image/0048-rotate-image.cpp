class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();

        vector<vector<int>> copy(n , vector<int>(m , 0));
        int p = 0 , q = 0;

        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                copy[j][n-1-i] = mat[i][j];
            }
        }

        mat = copy;
    }
};