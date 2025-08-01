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

        // if(day >= days[ind]) cost = func(ind + 1 , day , days , costs); redundant step 

        miniCost = min(miniCost , cost);

        for(int i = 0 ; i < 3 ; i++){
            /*
            Why are u only jumping to the next step ?? Suppose , u need a pass for days[ind] = 4 and you buy a 7 day , if you buy a 7 day pass at day 4 , so you can travel on day 4,5,6,7,8,9,10 , so just skip the these days after buying that 7 day ticket , just go to the index with day >= 11
            
            cost = costs[i] + func(ind + 1 , days[ind] + t[i] - 1 , days , costs);
            */
            int j = ind;
            while(j < days.size() && days[j] <= days[ind] + t[i] - 1){
                j++;
            }

            cost = costs[i] + func(j , days[ind] + t[i] - 1 , days , costs);

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