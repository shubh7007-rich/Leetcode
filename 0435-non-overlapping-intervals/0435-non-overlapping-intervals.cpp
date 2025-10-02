class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        int cnt = 0;

        sort(inv.begin() , inv.end() , [](vector<int>& a , vector<int>& b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int start = inv[0][0] , end = inv[0][1];
        for(int i = 1 ; i < inv.size() ; i++){
            if(inv[i][0] >= end){
                start = inv[i][0];
                end = inv[i][1];
            }else{
                cnt++;
            }
        }

        return cnt;
    }
};