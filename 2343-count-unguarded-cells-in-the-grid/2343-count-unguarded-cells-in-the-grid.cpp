class Solution {
public:
    vector<vector<int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};

    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {


        int cnt = 0;

        queue<pair<int , int>> que;

        vector<vector<int>> grid(n , vector<int>(m , 0));

        for(auto & vec : guards){
            grid[vec[0]][vec[1]] = 2;
        }

        for(auto & vec : walls){
            grid[vec[0]][vec[1]] = -1;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    que.push({i , j});
                }
            }
        }

        while(!que.empty()){
            auto p = que.front();
            que.pop();

            int r = p.first , c = p.second;

            int r1 = r - 1;
            while(r1 >= 0 && grid[r1][c] != -1 && grid[r1][c] != 2){
                grid[r1][c] = 1;
                r1--;
            }
            r1 = r + 1;
            
            while(r1 < n && grid[r1][c] != -1 && grid[r1][c] != 2){
                grid[r1][c] = 1;
                r1++;
            }

            int c1 = c-1;
            while(c1 >= 0 && grid[r][c1] != -1 && grid[r][c1] != 2){
                grid[r][c1] = 1;
                c1--;
            }
            
            c1 = c + 1;
            while(c1 < m && grid[r][c1] != -1 && grid[r][c1] != 2){
                grid[r][c1] = 1;
                c1++;
            }
        }


        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};