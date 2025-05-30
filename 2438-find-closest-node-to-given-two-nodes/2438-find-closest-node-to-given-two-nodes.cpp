class Solution {
public:
    void dfs(int node , vector<int>& dist , vector<vector<int>>& adj , int d , vector<int>& vis){
        dist[node] = d;
        vis[node] = 1;

        for(int neigh : adj[node]){
            if(neigh == -1) continue;
            if(!vis[neigh]){
                dfs(neigh , dist , adj , d+1 , vis);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < n ; i++){
            if(edges[i] == -1) continue;

            adj[i].push_back(edges[i]);
        }
        vector<int> dist1(n , -1) , dist2(n , -1);
        vector<int> vis1(n , 0) , vis2(n , 0);

        dfs(node1 , dist1 , adj , 0 , vis1);
        dfs(node2 , dist2 , adj , 0 , vis2);

        int mini = INT_MAX , miniNode = -1 ;

        for(int i = 0 ; i < n ; i++){
            if(dist1[i] != -1 && dist2[i] != -1){
                int dist = max(dist1[i] , dist2[i]);
                if(mini > dist){
                    mini = dist;
                    miniNode = i;
                }
            }
        }

        return miniNode;
    }
};