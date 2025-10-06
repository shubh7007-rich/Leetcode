class Solution {
public:
    vector<vector<int>> directions = {{1,0} , {-1,0} , {0,1} , {0,-1}};

    bool isSafe(int r , int c, int n){
        return (r >= 0 && r < n && c >= 0 && c < n);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));

        dist[0][0] = grid[0][0];

        queue<pair<int , pair<int , int>>> que;

        que.push({grid[0][0] , {0 , 0}});

        while(!que.empty()){
            auto p = que.front();
            que.pop();

            int t = p.first , r = p.second.first , c = p.second.second;

            for(auto & vec : directions){
                int r1 = r + vec[0] , c1 = c + vec[1];

                if(isSafe(r1 , c1 , n)){
                    int newTime = max(t , grid[r1][c1]);

                    if(newTime < dist[r1][c1]){
                        dist[r1][c1] = newTime;

                        que.push({newTime , {r1 , c1}});
                    }
                }
            }

        }

        return dist[n-1][n-1];
    }
};