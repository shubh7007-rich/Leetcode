class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // t.c - O(n*n)

        // for(int i = 0 ; i < nums.size() ; i++){
        //     for(int j = i+1 ; j < nums.size() ; j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i , j};
        //         }
        //     }
        // }

        // return {-1 , -1};

        // Optimal approach --> t.c O(n)

        unordered_map<int , int> mp;

        for(int i = 0 ; i < nums.size() ; i++){
            int check = target - nums[i];

            if(mp.find(check) != mp.end()){
                return {i , mp[check]};
            }

            mp[nums[i]] = i;
        }

        return {-1 , -1};
    }
};