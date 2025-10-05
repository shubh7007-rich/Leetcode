class Solution {
public:
    vector<vector<int>> directions = {{1 ,0} , {-1, 0} , {0, 1} , {0 , -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>> dist(n , vector<int>(m , -1));

        queue<pair<int , int>> que;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    que.push({i , j});
                }
            }
        }
        int lvl = 1;

        while(!que.empty()){
            int size = que.size();

            while(size--){
                auto p = que.front();
                que.pop();

                int r = p.first , c = p.second;

                for(auto & vec : directions){
                    int r1 = r + vec[0] , c1 = c + vec[1];

                    if(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && dist[r1][c1] == -1){
                        dist[r1][c1] = lvl;
                        que.push({r1 , c1});
                    }
                }
            }
            lvl++;
        }

        return dist;
    }   
};