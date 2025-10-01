class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles , empty = numBottles;

        while(true){
            int n = empty/numExchange;
            int rem = empty % numExchange;

            if(n == 0) break;

            ans += n;

            empty = n + rem;
        }

        return ans;
    }
};