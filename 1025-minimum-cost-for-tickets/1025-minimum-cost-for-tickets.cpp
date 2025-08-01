class Solution {
public:
    int t[3] = {1 , 7 , 30};

     int dp[395][395];

    int func(int ind , int day , vector<int>& days, vector<int>& costs){
        if(ind >= days.size()){
            return 0;
        }
        int cost = INT_MAX , miniCost = INT_MAX;

        if(dp[ind][day] != -1) return dp[ind][day];

        if(day >= days[ind]) cost = func(ind + 1 , day , days , costs);

        miniCost = min(miniCost , cost);

        for(int i = 0 ; i < 3 ; i++){
            cost = costs[i] + func(ind + 1 , days[ind] + t[i] - 1 , days , costs);

            miniCost = min(miniCost , cost);
        }

        return dp[ind][day] = miniCost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int day = 0 , ind = 0;

        memset(dp , -1 , sizeof(dp));

        return func(ind , day , days , costs);
    }
};