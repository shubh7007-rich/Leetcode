class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> freq;

        int i = 0  , n = nums.size();

        for(int j = 0 ; j < n ; j++){
            freq[nums[j]]++;

            if(j-i+1 > k+1){
                freq[nums[i]]--;

                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }

            if(freq.size() < j-i+1) return true;
        }

        return false;


    }
};