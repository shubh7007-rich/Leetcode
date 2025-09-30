class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int c = 0 , i = 0 , cnt = 0;
        unordered_map<int , int> mp;

        for(int j = 0 ; j < nums.size() ; j++){
            mp[nums[j]]++;

            while(mp.size() > k){
                mp[nums[i]]--;

                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
                c = 0;
            }

            while(mp[nums[i]] > 1){
                c++;
                mp[nums[i]]--;
                i++;

            }

            
            if(mp.size() == k) cnt += c + 1;
            
        }

        return cnt;
    }
};