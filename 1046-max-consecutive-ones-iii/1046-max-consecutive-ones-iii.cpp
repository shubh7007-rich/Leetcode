class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n1 = 0 , n0 = 0 , maxi = 0;

        int i = 0;

        // unordered_map<int , int> mp;

        for(int j = 0 ; j < nums.size() ; j++){
            if(nums[j] == 0){
                n0++;
            }

            while(n0 > k){
                if(nums[i] == 0){
                    n0--;
                }
                i++;
            }

            maxi = max(maxi , j-i+1);
        }

        return maxi;
    }
};