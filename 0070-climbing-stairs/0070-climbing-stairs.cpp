class Solution {
public:
    int dp[45];
    int func(int i , int n){
        if(i == n) return 1;

        if(i > n ) return 0;

        int s1 = 0 , s2;
        s1 = func(i + 1 , n);
        s2 = func(i+2 , n);

        return s1 + s2;

    }
    int climbStairs(int n) {
        return func(0 , n);
    }
};