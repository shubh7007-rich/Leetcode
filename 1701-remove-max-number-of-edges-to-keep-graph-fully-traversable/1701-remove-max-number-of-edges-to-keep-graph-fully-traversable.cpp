class Solution {
public:
    vector<int> parentA , rankA , parentB , rankB;

    int find(int node , vector<int>& parent){
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node] , parent);
    }

    void unionn(int n1 , int n2 , vector<int>& parent , vector<int>& rank){
        int p1 = find(n1 , parent) , p2 = find(n2 , parent);

        if(p1 == p2) return;

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }else if(rank[p2] > rank[p1]){
            parent[p1] = p2;
        }else{
            rank[p1]++;
            parent[p2] = p1;
        }
    }
    void intialize(int n){
        parentA.resize(n);
        rankA.resize(n , 0);
        parentB.resize(n);
        rankB.resize(n , 0);

        for(int i = 0 ; i < n ; i++){
            parentA[i] = i;
        }
        for(int i = 0 ; i < n ; i++){
            parentB[i] = i;
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        intialize(n+1);

        int cnt = 0;
        
        sort(edges.begin() , edges.end() , [](vector<int>& a , vector<int>& b){
            return a[0] > b[0];
        });

        for(vector<int>& vec : edges){
            int type = vec[0];
            int n1 = vec[1] , n2 = vec[2];

    
            if(type == 1){
                int p1 = find(n1 , parentA) , p2 = find(n2 , parentA);
                if(p1 == p2){
                    cnt++;
                }else{
                    unionn(p1 , p2 , parentA , rankA);
                }
            }else if(type == 2){
                int p1 = find(n1 , parentB) , p2 = find(n2 , parentB);
                if(p1 == p2){
                    cnt++;
                }else{
                    unionn(p1 , p2 , parentB , rankB);
                }
            }else{
                int p1 = find(n1 , parentA) , p2 = find(n2 , parentA) , p3 = find(n1 , parentB) , p4 = find(n2 , parentB);

                if(p1 == p2 && p3 == p4){
                    cnt++;
                }

                unionn(p1 , p2 , parentA , rankA);
                unionn(p3 , p4 , parentB , rankB);
            }
        }

        int c1 = 0 , c2 = 0;

        for(int i = 1 ; i < n+1 ; i++){   // start from 1 here , no 0 node
            if(i == find(i , parentA)) c1++;
            if(i == find(i , parentB)) c2++;

            if(c1 > 1 || c2 > 1) return -1;
        }

        return cnt;
    }
};