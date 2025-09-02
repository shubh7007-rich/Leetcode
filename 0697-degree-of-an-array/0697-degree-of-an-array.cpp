class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int deg = 0 , maxi = 0;

        unordered_map<int , int> freq1 , freq2;

        for(int i : nums){
            freq1[i]++;
            deg = max(deg , freq1[i]);
        }

        int i = 0 , mini = INT_MAX;

        for(int j = 0 ; j < nums.size() ; j++){
            freq2[nums[j]]++;

            maxi = max(maxi , freq2[nums[j]]);

            while(maxi >= deg){
                mini = min(mini , j-i+1);

                freq2[nums[i]]--;

                maxi = INT_MIN;

                for(auto [num , f] : freq2){
                    maxi = max(maxi , f);
                }
                i++;
            }
        }

        return mini;
    }
};