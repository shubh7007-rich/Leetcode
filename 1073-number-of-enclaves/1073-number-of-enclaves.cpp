class Solution {
public:
    vector<vector<int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};

    void dfs(int r , int c , vector<vector<int>>& grid){
        grid[r][c] = 0;

        for(vector<int>& vec : directions){
            int r1 = r + vec[0] , c1 = c + vec[1];

            if(r1 >= 0 && r1 < grid.size() && c1 >= 0 && c1 < grid[0].size() && (grid[r1][c1] == 1)){
                grid[r1][c1] = 0;
                dfs(r1 ,c1 , grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        stack<pair<int , int>> st;

        int n = grid.size() , m = grid[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    st.push({i , j});
                }
            }
        }


        while(!st.empty()){

            auto p = st.top();
            st.pop();

            int i = p.first , j = p.second;

            if(grid[i][j] == 0) continue;

            dfs(i , j , grid);
        }

        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) cnt++;
            }
        }


        return cnt;
    }
};