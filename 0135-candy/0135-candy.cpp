class Solution {
public:
    int candy(vector<int>& ratings) {
        /*
            [3 , 2 , 1 , 2]  --> ratings
            [3 , 2 , 1 , 2]


            [1 , 3 , 4 , 5 , 2]
            [1 , 2 , 3 , 4 , 1]
        
        */
        int n = ratings.size();
        vector<int> ans(n , 1);

        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                ans[i] = max(ans[i] , ans[i-1] + 1);
            }
        }

        for(int i = n-2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                ans[i] = max(ans[i] , ans[i+1] + 1);
            }
        }

        return accumulate(ans.begin() , ans.end() , 0);
    }
}; 