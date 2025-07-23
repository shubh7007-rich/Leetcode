class Solution {
public:
    #define ll long long
    vector<vector<int>> directions = {{1, 0} , {-1, 0} , {0 , 1} , {0 , -1}};

    ll dfs(int r , int c , vector<vector<int>>& grid , int  n , int m , vector<vector<int>>& vis){
        ll sum = grid[r][c];
        vis[r][c] = 1;
        
        for(auto vec : directions){
            int r1 = r + vec[0] , c1 = c + vec[1];

            if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && !vis[r1][c1] && grid[r1][c1] > 0){
                sum += dfs(r1 , c1 , grid , n , m , vis);
            }
        }

        return sum;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size(), cnt = 0;
        vector<vector<int>> vis(n , vector<int>(m , 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    ll sum = dfs(i , j , grid , n , m , vis);

                    if(sum % k == 0) cnt++;
                }
            }
        }

        return cnt;
    }
}; 