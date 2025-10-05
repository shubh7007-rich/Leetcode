class Solution {
public:
    int find(int node , vector<int>& parent){
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node] , parent);
    }

    bool merge(int n1 , int n2 , vector<int>& parent , vector<int>& rank){
        int p1 = find(n1 , parent) , p2 = find(n2 , parent);

        if(p1 == p2) return false;

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }else if(rank[p1] < parent[p2]){
            parent[p1] = p2;
        }else{
            rank[p1]++;
            parent[p2] = p1;
        }

        return true;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> parent(n) , rank(n , 0);

        int components = n;

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j || !isConnected[i][j]) continue;

                if(merge(i , j , parent , rank)) components--;
            }
        }


        return components;
    }
};