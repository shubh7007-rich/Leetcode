class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();

        vector<vector<int>> copy(n , vector<int>(m , 0));
        int p = 0 , q = 0;

        for(int j = m-1 ; j >= 0 ; j--){
            for(int i = 0 ; i < n ; i++){
                copy[i][j] = mat[p][q];
                q++;
            }
            p++;q=0;
        }

        mat = copy;
    }
};