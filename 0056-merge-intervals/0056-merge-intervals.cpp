class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inv) {
        sort(inv.begin() , inv.end() , [&](vector<int>& a , vector<int>& b){
            return a[0] < b[0];
        });
        
        int start = inv[0][0] , end = inv[0][1];

        

        vector<vector<int>> ans;

        for(vector<int>& vec : inv){
            int s1 = vec[0] , s2 = vec[1];

            if(s1 > end){
                ans.push_back({start , end});
                start = s1 , end = s2;
            }else{
                end = max(end , s2);
            }
        }
        ans.push_back({start , end});

        return ans;
    }
};