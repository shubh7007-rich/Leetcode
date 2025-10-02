class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& newinv) {
        vector<vector<int>> ans;

        // if we already have been given non overlapping intervals so just traverse in the inv array and check if u can merge it with some intervals if not just push it and rest of the intervals;

        int i = 0;
        while(i < inv.size()){
            if(inv[i][1] < newinv[0]){
                ans.push_back(inv[i]);
            }else if(inv[i][0] > newinv[1]){
                break;
            }else{
                newinv[0] = min(inv[i][0] , newinv[0]);
                newinv[1] = max(inv[i][1] , newinv[1]);
            }

            i++;
        }

        ans.push_back(newinv);

        while(i < inv.size()){
            ans.push_back(inv[i]);
            i++;
        }

        return ans;
    }
}; 