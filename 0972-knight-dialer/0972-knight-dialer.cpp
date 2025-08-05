class Solution {
public:
    int mod = 1e9 + 7;

    int dp[4][3][5000];
    
    vector<vector<int>> directions = {{-2,-1} , {-2,1} , {-1,-2} , {1,-2} , {2,-1} , {2,1} , {-1,2} , {1,2}};
    int func(int r, int c , vector<vector<int>>& phonePad , int k){
        if(r < 0 || r >= 4 || c < 0 || c >= 3 || (r == 3 && c == 0) || (r == 3 && c == 2)){
            return 0;
        }
        if(k == 0) return 1;

        if(dp[r][c][k] != -1) return dp[r][c][k];

        int ways = 0;
        for(vector<int>& dir : directions){
            ways = (ways + func(r + dir[0] , c + dir[1] , phonePad , k-1 )) % mod;
        }

        return dp[r][c][k] = ways;
    }
    int knightDialer(int n) {
        memset(dp , -1 , sizeof(dp));
        
        vector<vector<int>> phonePad(4 , vector<int>(3 , 0));
        int p = 1;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                phonePad[i][j] = p;
                p++;
            }
        }

        int cnt = 0;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if((i == 3 && j == 0) || (i == 3 && j == 2)) continue;

                cnt = (cnt + func(i , j , phonePad , n-1)) % mod;
            }
        }

        return cnt;
    }
};