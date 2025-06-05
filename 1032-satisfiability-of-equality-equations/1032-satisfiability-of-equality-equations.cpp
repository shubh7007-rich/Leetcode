class Solution {
public:
    vector<int> parent , rank;

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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26 , 0);

        for(int i = 0 ; i < 26 ; i++){
            parent[i] = i;
        }

        for(string & str : equations){
            if(str[1] == '=')unionn(str[0]-'a' , str[3]-'a' , parent , rank);
        }
        for(string & str : equations){
            if(str[1] == '!'){
                int p1 = find(str[0]-'a' , parent);
                int p2 = find(str[3]-'a' , parent);

                if(p1 == p2) return false;
            }
        }

        return true;
    }
};