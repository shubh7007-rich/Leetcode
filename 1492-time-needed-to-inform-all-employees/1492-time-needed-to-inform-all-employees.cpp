class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int maxi = 0 ;

        queue<pair<int , int>> que;

        vector<vector<int>> adj(n);

        for(int i = 0 ; i < n ; i++){
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }

        que.push({headID , 0});

        while(!que.empty()){
            auto p = que.front();
            que.pop();

            int node = p.first , t = p.second;
            maxi = max(maxi , t);

            for(auto neigh : adj[node]){
                que.push({neigh , t + informTime[node]});
            }
        }

        return maxi;
    }
};