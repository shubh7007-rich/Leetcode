class Solution {
public:
    vector<vector<int>> directions = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        /*
            [2 , 2 , 2]
            [2 , 2 , 0]
            [0 , 2 , ]
        */
        queue<pair<int , int>> que;

        int n = grid.size() , m = grid[0].size() , f = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    que.push({i , j});
                }

                if(grid[i][j] == 1) f++;
            }
        }

        if(f == 0) return 0;
        
        int lvl = 0;
        while(!que.empty()){
            int size = que.size();

            while(size--){
                auto p = que.front();
                que.pop();

                int r = p.first , c = p.second;

                for(auto vec : directions){
                    int r1 = r + vec[0] , c1 = c + vec[1];

                    if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && grid[r1][c1] == 1){
                        grid[r1][c1] = 2;
                        que.push({r1 , c1});
                    }
                }
            }
            lvl++;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return lvl - 1;
    }
};