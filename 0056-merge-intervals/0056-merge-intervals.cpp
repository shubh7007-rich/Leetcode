class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inv) {
        sort(inv.begin() , inv.end() , [](vector<int> & a , vector<int> & b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        int start = inv[0][0] , end = inv[0][1];

        vector<vector<int>> ans;

        for(int i = 1 ; i < inv.size() ; i++){
            if(inv[i][0] > end){
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