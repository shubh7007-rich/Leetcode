class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& newinv) {
        vector<vector<int>> ans;
        inv.push_back(newinv);
        sort(inv.begin() , inv.end());

        int start = inv[0][0] , end = inv[0][1];

        int yo = newinv[0] , ya = newinv[1];

        for(int i = 1 ; i < inv.size() ; i++){
            if(end < inv[i][0]){
                ans.push_back({start , end});
                start = inv[i][0];
                end = inv[i][1];
            }else{
                end = max(end , inv[i][1]);
            }
        }

        ans.push_back({start , end});


        return ans;
    }
}; 