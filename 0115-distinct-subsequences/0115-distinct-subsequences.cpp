class Solution {
public:
    int dp[1000][1000];

    int countWays(string& s, string& t, int i, int j) {
        if (j == t.size())
            return 1; // matched entire t
        if (i == s.size())
            return 0; // no s left, can't match

        if(dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = countWays(s, t, i + 1, j + 1) + countWays(s, t, i + 1, j);
        } else {
            return dp[i][j] = countWays(s, t, i + 1, j);
        }
    }

    int numDistinct(string s, string t) { 
        memset(dp , -1 , sizeof(dp));

        return countWays(s, t, 0, 0); }
};