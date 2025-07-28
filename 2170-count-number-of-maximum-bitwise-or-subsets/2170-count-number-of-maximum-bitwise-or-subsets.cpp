class Solution {
public:
    int cnt = 0 ;

    int func(int ind , int orr , vector<int>& nums , int maxOr){
        if(ind >= nums.size()){
            return (orr == maxOr) ? 1 : 0;
        }
        return func(ind+1 , orr , nums , maxOr) + func(ind+1 , orr | nums[ind] ,nums, maxOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int orr = 0 , maxOr = 0;

        for(int & i : nums) maxOr |= i;
        
        return func(0 ,orr , nums , maxOr); 
    }
};