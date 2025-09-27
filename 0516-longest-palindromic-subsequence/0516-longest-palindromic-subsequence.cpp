class Solution {
public:
    int dp[1000][1000];
    int func(int l , int r , string & s){
        if(l == r){
            return 1;
        }
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int op1 = 0 , op2 = 0 , op3 = 0;

        if(s[l] == s[r]){
            op1 = 2 + func(l+1 , r-1 , s);
        }else{
            op2 = func(l+1 , r , s);
            op3 = func(l , r-1 , s);
        }

        return dp[l][r] = max({op1 , op2 , op3});
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        memset(dp , -1 , sizeof(dp));

        return func(0 , n-1 , s);
    }
};