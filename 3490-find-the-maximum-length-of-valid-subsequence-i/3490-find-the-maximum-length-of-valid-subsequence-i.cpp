class Solution {
public:
    int solve(vector<vector<vector<int>>> &dp , vector<int> &nums , int parity , int prev , int ind)
{
    if(ind==nums.size())
    {
        return 0;
    }
    if(dp[parity+1][prev+1][ind]!=-1)
    {
        return dp[parity+1][prev+1][ind];
    }
    int ans= 0;
    if(parity==-1  &&  prev==-1)
    {
        ans = 1 + solve(dp , nums , -1 , nums[ind] , ind+1);
    }
    else if(parity==-1  &&  prev!=-1)
    {
        ans = 1 + solve(dp , nums , (nums[ind] + prev)%2 , nums[ind] , ind+1);
    }
    else if(parity!=-1  &&  (nums[ind] + prev)%2==parity)
    {
        ans = 1 + solve(dp , nums , parity , nums[ind] , ind+1);
    }
    return dp[parity+1][prev+1][ind] = max(ans , solve(dp , nums , parity , prev , ind+1));
}

int maximumLength(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++)
    {
        nums[i] %= 2;
    }
    vector<vector<vector<int>>> dp(3 , vector<vector<int>> (3 , vector<int> (nums.size() , -1)));
    return solve(dp , nums , -1 , -1 , 0);
}
};