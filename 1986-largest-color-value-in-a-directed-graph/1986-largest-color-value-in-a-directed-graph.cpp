class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<int> indegree(n , 0);

        vector<vector<int>> adj(n);

        for(vector<int> & vec : edges){
            adj[vec[0]].push_back(vec[1]);
            indegree[vec[1]]++;
        }

        vector<vector<int>> dp(n , vector<int> (26 , 0));
        queue<int> que;

        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                que.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = 0 , countNodes = 0;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            countNodes++;
            ans = max(ans , dp[u][colors[u] - 'a']);

            for(auto neigh : adj[u]){

                for(int i = 0 ; i < 26 ; i++){
                    dp[neigh][i] = max(dp[neigh][i] , dp[u][i] + (colors[neigh] -'a' == i));
                }
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    que.push(neigh);
                }
            }
        }

        if(countNodes < n) return -1;


        return ans;


    }
};