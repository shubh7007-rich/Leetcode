class Solution {
public:
    int inf = -1e7;

    int dp[600][101][101];

    int func(int ind ,int c0 , int c1 ,int m, int n , unordered_map<int , pair<int , int>>& mp , int size){
        if(ind >= size){
            return 0;
        }

        int zero = mp[ind].first , one = mp[ind].second;

        if(dp[ind][c0][c1] != -1) return dp[ind][c0][c1];
        
        int take = inf;
        if((c0 + zero <= m) && (c1 + one <= n)){
            take = 1 + func(ind+1 , c0 + zero , c1 + one  , m , n , mp , size);
        }

        int notTake = func(ind+1 , c0 , c1 , m , n , mp , size);

        return dp[ind][c0][c1] = max(take , notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // preprocessing
         unordered_map<int , pair<int , int>> mp;

         int size = strs.size();

         memset(dp , -1 , sizeof(dp));

        for(int i = 0 ; i < strs.size() ; i++){
            int zero = 0 , one = 0;
            for(char ch : strs[i]){
                if(ch == '0'){
                    zero++;
                }else{
                    one++;
                }
            }
            mp[i] = {zero , one};
        }

        return func(0 ,0 , 0 , m , n , mp , size);
    }
};