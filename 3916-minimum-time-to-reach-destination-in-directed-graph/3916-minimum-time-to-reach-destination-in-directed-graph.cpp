class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int,int,int>>> adj(n);

        unordered_map<int , int> countOfNeigh;

        for(auto & vec: edges){
            int u = vec[0] ,v = vec[1] , s = vec[2] , e = vec[3];

            adj[u].push_back({v , s , e});
            countOfNeigh[u]++;
        }

        vector<int> dist(n , INT_MAX);

        dist[0] = 0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> que;
        unordered_map<int , int> c;
        que.push({0 , 0});

        while(!que.empty()){
            auto p = que.top();
            que.pop();

            int node = p.second , t = p.first;

            if(node == n-1) return t;

            bool flag = false;
            int mini = INT_MAX;

            for(auto [neigh , start , end] : adj[node]){
                if(t >= start && t <= end && (dist[neigh] == INT_MAX)){
                    dist[neigh] = t+1;
                    que.push({t+1 , neigh});
                }else if(t < start && dist[neigh] == INT_MAX){
                    if(mini > start){
                        mini = start;
                    }
                    
                }
            }

            if(mini != INT_MAX){
                que.push({mini , node});
            }

            

            
        }

        return -1;
    }
};