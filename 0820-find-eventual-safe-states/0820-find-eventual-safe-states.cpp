class Solution {
public:
    bool dfs(int node , vector<int>& vis , vector<int>& inRecursion , vector<vector<int>>& graph){
        vis[node] = 1;
        inRecursion[node] = 1;

        for(int neigh : graph[node]){
            if(vis[neigh] && inRecursion[neigh]) return true;

            if(!vis[neigh]){
               if (dfs(neigh , vis , inRecursion , graph)) return true;
            }
        }

        inRecursion[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        /*
            vis , inRecursion

            0 ---> 1  ---> 2
                         /
                       3

        */
        int n = graph.size();

        vector<int> vis(n , 0);
        vector<int> inRecursion(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i , vis , inRecursion , graph);
            }
        }

        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            if(!inRecursion[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
}; 