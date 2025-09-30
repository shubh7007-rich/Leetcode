class Solution {
public:
    int triangularSum(vector<int>& nums) {
        /*
            [1 ,2 , 3, 4 , 5]   k = 1 , n = 5
            4 
        */

        int n = nums.size();
        int k = 0;
        while(k < (n-1)){
            int p = nums[0];
            for(int i = 1 ; i < n-k ; i++){
                nums[i-1] = (p + nums[i]) % 10;
                p = nums[i];
            }
            k++;
        }

        return nums[0];
    }
};