class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> que;
        
        vector<int> indegree(numCourses , 0);
        
        vector<int> ans;
        
        vector<vector<int>> adj(numCourses);
        
        for(auto & vec : prerequisites){
            adj[vec[0]].push_back(vec[1]);
            
            indegree[vec[1]]++;
        }
        
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }
        
        while(!que.empty()){
            int size = que.size();
            
            while(size--){
                int fro = que.front();
                
                que.pop();
                
                ans.push_back(fro);
                
                for(int neigh : adj[fro]){
                    indegree[neigh]--;
                    
                    if(indegree[neigh] == 0){
                        que.push(neigh);
                    }
                }
            }
        }
        
        return (ans.size() == numCourses);
    }
};