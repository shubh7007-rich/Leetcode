class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        queue<pair<int , int>> que;

        int n = mat.size() , m = mat[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    que.push({i , j});
                }
            }
        }

        while(!que.empty()){
            auto p = que.front();
            que.pop();

            int r = p.first , c = p.second;

            int N = r-1 , S = r+1 , E = c + 1 , W = c - 1;

            while(N >= 0){
                mat[N][c] = 0;
                N--;
            }
            while(S < n){
                mat[S][c] = 0;
                S++;
            }
            while(E < m){
                mat[r][E] = 0;
                E++;
            }
            while(W >= 0){
                mat[r][W] = 0;
                W--;
            }
        }
    }
};