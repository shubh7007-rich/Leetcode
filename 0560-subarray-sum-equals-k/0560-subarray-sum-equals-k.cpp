class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            brute force approach --> O(n^3)

            better approach --> O(n^2)

            Optimal approach -->

            [1 , 2 , 3 , 2 , 1 , 1 , 2 , 3]


            sum = 6

            int x = sum - k

            k = 4 

            [1 , 2 , 5 , 0 , 1 , 2 , 2 , 4 , 5 , 9 ]  , k = 3

            1 + 2 + 5 + 1 + 2 = 11
            k = 3
            11 - 3 = 8

            8 + x = 11

        */
        int n = nums.size() , cnt = 0 , sum = 0;
        
        unordered_map<int , int> mp;
        mp[0] = 1;

        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];

            int target = sum - k;  // k - k = 0

            if(mp.count(target)){
                cnt += mp[target];
            }

            mp[sum]++;
        }


        return cnt;
    }
};