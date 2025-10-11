class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            brute force approach --> 

        */
        int n = nums.size() , cnt = 0;
        for(int i = 0 ; i  < n ; i++){
            int sum = 0;
            for(int j = i ; j < n ; j++){
                sum += nums[j];

                // for(int k = i ; k <= j ; k++){
                //     sum += nums[k];
                // }

                if(sum == k) cnt++;
            }
        }



        return cnt;
    }
};