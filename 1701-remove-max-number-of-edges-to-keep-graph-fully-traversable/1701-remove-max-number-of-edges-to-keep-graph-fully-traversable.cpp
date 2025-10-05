class Solution {
public:
    int find(int node , vector<int>& parent){
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node] , parent);
    }

    bool unionn(int n1 , int n2 , vector<int>& parent , vector<int>& rank){
        int p1 = find(n1 , parent) , p2 = find(n2 , parent);

        if(p1 == p2) return false;

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }else if(rank[p2] > rank[p1]){
            parent[p1] = p2;
        }else{
            rank[p1]++;
            parent[p2] = p1;
        }

        return true;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentA(n+1) , rankA(n+1 , 0) , parentB(n+1) , rankB(n+1 , 0);

        for(int i = 1 ; i < n+1 ; i++){
            parentA[i] = i;
            parentB[i] = i;
        }
        // i will use all edges of type 3 as it will most benefitical bcz that edge can be used by both alice and bob

        int cnt = 0;
        for(auto vec : edges){
            if(vec[0] == 3){
                int p1 = find(vec[1] , parentA) , p2 = find(vec[2] , parentA);
                int p3 = find(vec[1] , parentB) , p4 = find(vec[2] , parentB);

                if(p1 == p2 && p3 == p4){
                    cnt++;
                }else{
                    unionn(vec[1] , vec[2] , parentA , rankA);
                    unionn(vec[1] , vec[2] , parentB , rankB);
                } 
            }
        }
        for(auto vec : edges){
            if(vec[0] != 3){
                if(vec[0] == 1){
                    if(!unionn(vec[1] , vec[2] , parentA , rankA)) cnt++;
                }else{
                    if(!unionn(vec[1] , vec[2] , parentB , rankB)) cnt++;
                }
            }
        }
        // for(int i = 1;  i< n+1 ; i++){  instead whenever u need a parent use find function not parent array
        //     find(i , parentA);
        //     find(i , parentB);
        // }
        int c1 = 0 , c2 = 0 ;
        for(int i = 1; i < n+1 ; i++){
            if(find(i , parentA) == i) c1++;
            if(find(i , parentB) == i) c2++;

            if(c1 > 1 || c2 > 1) return -1;
        }

        return cnt;
    }
};