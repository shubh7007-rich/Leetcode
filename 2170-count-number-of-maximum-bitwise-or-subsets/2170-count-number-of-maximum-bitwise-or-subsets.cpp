class Solution {
public:
    int cnt = 0 , maxi = 0;

    void func(int ind , int orr , vector<int>& nums){
        if(ind >= nums.size()){
            if(orr > maxi){
                cnt = 1;
                maxi = orr;
            }else{
                if(orr == maxi){
                    cnt++;
                }
            }

            return;
        }
        int temp = orr;
        orr = orr | nums[ind];
        func(ind + 1 , orr , nums);
        func(ind + 1 , temp , nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int orr = 0;
        func(0 ,orr , nums);
        return cnt;
    }
};