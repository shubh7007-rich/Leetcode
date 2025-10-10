class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevBuy = INT_MAX , sum = 0 ;

        for(int i : prices){
            if(i > prevBuy){
                sum += (i - prevBuy);
                prevBuy = i;
            }else{
                prevBuy = i;
            }
        }

        return sum;
    }
};