class Solution {
public:
    /* 
        So here for every index i need satisfy the conditions
        1. Each child must have at least one candy.
        2. Children with a higher rating get more candies than their neighbors.
        So for every index (expect the first and the last) we need to check it's left and  right neighbour to satisfying the condition
        So for ques like these first go from L 2 R satisfying the condition left neighbour ko dekhte huwe and then go from R 2 L satisfying the condition right neighbour ko dekhte huwe
    */
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n , 1);

        if(n == 1) return 1;

        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1] + 1;
            }
        }

        for(int i = n-2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1] && ans[i] <= ans[i+1]){
                ans[i] = ans[i+1] + 1;
            }
        }
        int sum = 0;

        for(int & i : ans) sum += i;

        return sum;
    }
};