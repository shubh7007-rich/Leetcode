class Solution {
public:
    pair<int , int> bfs(int node , vector<vector<int>>& adj , vector<int>& color){
        int even = 0 , odd = 0;

        queue<int> que;
        que.push(node);
        int c = 0;
        while(!que.empty()){
            int size = que.size();
            if(c == 0){
                even += size;
            }else{
                odd += size;
            }
            while(size--){
                int fro = que.front();
                que.pop();
                
                color[fro] = c;

                for(auto neigh : adj[fro]){
                    if(color[neigh] == -1){
                        que.push(neigh);
                    }
                }
            }
            c = !c;
        }

        return {even , odd};
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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

        // 0 aur uske adjacent ka nikal le

        vector<int> color1(n1 , -1) , color2(n2 , -1);

        auto [evenCount , oddCount] = bfs(0 , adj1 , color1);

        for(int i = 0 ; i < n1 ; i++){
            if(color1[i] == 0){
                ans1[i] = evenCount;
            }else{
                ans1[i] = oddCount;
            }
        }

        auto [evenCount1 , oddCount1] = bfs(0 , adj2 , color2);

        for(int i = 0 ; i < n1 ; i++){
            ans1[i] += max(evenCount1 , oddCount1);
        }
        return ans1;
    }
};