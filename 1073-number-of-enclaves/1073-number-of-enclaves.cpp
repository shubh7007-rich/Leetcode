class Solution {
public:
    vector<vector<int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};

    void dfs(int r , int c , vector<vector<int>>& grid){
        grid[r][c] = 2;

        for(auto & vec : directions){
            int r1 = r + vec[0] , c1 = c + vec[1];

            if(r1 >= 0 && r1 < grid.size() && c1 >= 0 && c1 < grid[0].size() && grid[r1][c1] == 1){
                dfs(r1 , c1 , grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        /*
            The problem states we need to return the number of land cells from which we cannot walk off the boundary , 
            So the brute way will be to go each land cell and then try to go outwards and check if we were able to go outside the boundary

            but a better way will be to think like all the land cells on the boundary can be used to walk off the boundary  and all the land cells we can reach from these boundary land cells will also be the land cells through which we can walk off the boundary , so 

            so just calculate the number of land cells we can reach from boundary cells

        */
        int n = grid.size() , m = grid[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1){
                        dfs(i , j , grid);
                    }
                }
            }
        }
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};