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

        for(int i = 0 ; i < 3 ; i++){
            int temp = days[ind] + t[i] - 1;
            int j = ind + 1;
            while(j < days.size() && temp >= days[j]){
                j++;
            }
            cost = costs[i] + func(j , temp , days , costs);
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