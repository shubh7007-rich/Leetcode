class Solution {
public:
    bool dfs(int node , vector<vector<int>>& adj ,stack<int>& st, vector<int>& vis , vector<int>& inCycle){
        vis[node] = 1;
        inCycle[node] = 1;
        // order.push_back(node);

        for(int neigh : adj[node]){
            if(inCycle[neigh]) return true;

            if(!vis[neigh]){
                if(dfs(neigh , adj , st , vis , inCycle)) return true;
            }
        }

        inCycle[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        /*
            [x , y]  --> to cake course x you first need to complete course y

            [[1,0],[2,0],[3,1],[3,2]]

               > 1
              /   \ 
            0      > 3
              \   /
                > 2
        */

        /*
            so as we know there is an ordering that needs to be followed i.e one course (node) has to be come first or completed before the other , so that hints to topoloical sort

            Return the ordering of courses you should take to finish all courses.

        That means we need a linear ordering of nodes such that for every edge u → v, u appears      before v.

        */

        /* using kahn algorithm

        queue<int> que;

        vector<vector<int>> adj(n);
        vector<int> indegree(n , 0);

        for(auto & vec : edges){
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }

        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }
        vector<int> order;

        while(!que.empty()){
            int node = que.front();
            que.pop();

            order.push_back(node);

            for(int neigh : adj[node]){
                indegree[neigh]--;

                if(indegree[neigh] == 0){
                    que.push(neigh);
                }
            }
        }

        return (order.size() != n) ? vector<int>{} : order;

        */

        /* Using Dfs */
        
        vector<int> order;

        vector<vector<int>> adj(n);
        stack<int> st;
        vector<int> vis(n , 0);
        vector<int> inCycle(n , 0);

        for(auto & vec : edges){
            adj[vec[1]].push_back(vec[0]);
        }

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(dfs(i , adj , st , vis , inCycle)) return {};
            }
        }

        while(!st.empty()){
            order.push_back(st.top());
            st.pop();
        }

        return order;
    }

};