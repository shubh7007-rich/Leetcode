#define ll long long
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll cnt = 1;

        int i = 0;

        for(int j = 1 ; j < prices.size() ; j++){
            if(prices[j] - prices[j-1] != -1){
                i = j;
                cnt++;
            }else{
                cnt += j - i + 1;
            }
        }

        return cnt;
    }
};