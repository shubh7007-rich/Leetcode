class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // appraoch 1 - generate all subsets and check maximum

        int n = nums.size() ,maxOr = 0 , cnt = 0;

        for(int & i : nums) maxOr |= i;

        for(int i = 0 ; i < (1 << n) ; i++){
            int orr = 0;
            for(int j = 0 ; j < nums.size() ; j++){
                if(i & (1 << j)){
                    orr |= nums[j];
                }
            }

            if(orr == maxOr) cnt++;
        }

        return cnt;


        // approach 2 - recursion , T.C - 2^n
    }
};