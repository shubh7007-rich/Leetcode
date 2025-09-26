#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string str) {
        int n = str.length();
        int dp[n+1];
        dp[0] = 1;

        unordered_map<char , int> mp;

        for(int s = 1 ; s < n+1 ; s++){
            if(mp.find(str[s-1]) != mp.end()){
                int m = mp[str[s-1]];
                dp[s] = (2 * 1ll * dp[s-1] - dp[m-1] + mod) % mod ;
            }else{
                dp[s] = (2 * 1ll * dp[s-1]) % mod;
            }
            mp[str[s-1]] = s;
        }

        return (dp[n] - 1 + mod) % mod;
    }
};