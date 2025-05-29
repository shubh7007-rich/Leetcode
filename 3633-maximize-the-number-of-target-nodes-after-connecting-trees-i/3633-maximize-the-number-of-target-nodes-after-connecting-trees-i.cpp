class Solution {
public:
    void bfs(int node , vector<int>& ans , int k , vector<vector<int>>& adj , int n ){
        vector<int> vis(n , 0);
        int cnt = 0;
        queue<int> que;
        que.push(node);
        vis[node] = 1;
        int lvl = 0;
        while(!que.empty()){
            int size = que.size();
            if(lvl <= k){
                cnt += size;
            }else{
                break;
            }

            while(size--){
                int fro = que.front();
                que.pop();

                for(auto & neigh : adj[fro]){
                    if(!vis[neigh]){
                        vis[neigh] = 1;
                        que.push(neigh);
                    }
                }
            }
            lvl++;
        }

        ans[node] = cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size()+1 , n2 = edges2.size()+1;
        vector<vector<int>> adj1(n1) , adj2(n2);

        for(vector<int>& vec : edges1){
            adj1[vec[0]].push_back(vec[1]);
            adj1[vec[1]].push_back(vec[0]);
        }
        for(vector<int>& vec : edges2){
            adj2[vec[0]].push_back(vec[1]);
            adj2[vec[1]].push_back(vec[0]);
        }
        vector<int> ans1(n1) , ans2(n2);

        for(int i = 0 ; i < n1 ; i++){
            bfs(i , ans1 , k , adj1 , n1);
        }
        int maxi = 0;
        for(int i = 0 ; i < n2 ; i++){
            bfs(i , ans2 , k-1 , adj2 , n2);
            maxi = max(maxi , ans2[i]);
        }

        for(int i = 0 ; i < n1 ; i++) ans1[i] += maxi;

        return ans1;
    }
};