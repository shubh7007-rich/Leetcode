class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0 , n = nums.size() , sum = 0 , maxi = 0;

        unordered_map<int , int> mp;
        for(int j = 0 ; j < n ; j++){
            sum += nums[j];
            mp[nums[j]]++;

            while(i < j && (mp.size() < j-i+1)){
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);

                i++;
            }
            maxi = max(sum , maxi);
        }

        return maxi;
    }
};