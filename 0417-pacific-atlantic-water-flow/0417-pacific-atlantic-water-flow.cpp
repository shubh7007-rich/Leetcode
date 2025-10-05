class Solution {
public:
    vector<vector<int>> directions = {{-1,0} , {1,0} , {0,-1} , {0,1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();
        vector<vector<int>> marked(n , vector<int>(m, 0));

        queue<pair<int , int>> que;

        for(int i = 1 ; i < n ; i++){
            que.push({i , 0});
            marked[i][0]++;
        }
        for(int i = 0 ; i < m ; i++){
            que.push({0,i});
            marked[0][i]++;
        }

        while(!que.empty()){
            auto p = que.front();
            que.pop();

            int r = p.first , c = p.second;

            for(vector<int>& vec : directions){
                int r1 = r + vec[0] , c1 = c + vec[1];

                if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && marked[r1][c1] == 0 && heights[r1][c1] >= heights[r][c]){
                    marked[r1][c1] = 1;
                    que.push({r1 , c1});
                }
            }
        }

        vector<vector<int>> vis(n , vector<int>(m, 0));

        for(int i = 0 ; i < n ; i++){
            que.push({i , m-1});
            vis[i][m-1] = 1;
            marked[i][m-1]++;
        }

        for(int i = 0 ; i < m-1 ; i++){
            que.push({n-1 , i});
            vis[n-1][i] = 1;
            marked[n-1][i]++;
        }

        while(!que.empty()){
            auto p = que.front();
            que.pop();

            int r = p.first , c = p.second;

            for(vector<int>& vec : directions){
                int r1 = r + vec[0] , c1 = c + vec[1];

                if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && vis[r1][c1] == 0 && heights[r1][c1] >= heights[r][c]){
                    marked[r1][c1]++;
                    que.push({r1 , c1});
                    vis[r1][c1] = 1;
                }
            }
        }


        vector<vector<int>> ans;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(marked[i][j] == 2){
                    ans.push_back({i , j});
                }
            }
        }

        return ans;
    }
};