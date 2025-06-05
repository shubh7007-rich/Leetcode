class Solution {
public:
    char find(int ch1 ,vector<int>& parent){
        if(ch1 == parent[ch1]) return ch1;

        return parent[ch1] = find(parent[ch1] , parent);
    }

    void unionn(int n1 , int n2 , vector<int>& parent){
        int p1 = find(n1 , parent) , p2 = find(n2 , parent);

        if(p1 == p2) return;

        if(p1 < p2){
            parent[p2] = p1;
        }else{
            parent[p1] = p2;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26 , 0);

        for(int i = 0 ; i < 26 ; i++){
            parent[i] = i;
        }

        for(int i  = 0 ; i < s1.length() ; i++){
            unionn(s1[i]-'a' , s2[i]-'a' , parent);
        }

        for(int i = 0 ; i < baseStr.length() ; i++){
            int p1 = find(baseStr[i]-'a' , parent) , p2 = find(baseStr[i]-'a' , parent);
            baseStr[i] = p1 + 'a';
        }

        return baseStr;
    }
};