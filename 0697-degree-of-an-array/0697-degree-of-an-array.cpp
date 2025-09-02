class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // Approach 1 - just expand window until we find the maximum frequency equals to deg and shrink when maximum freq in that window >= deg

        // int deg = 0 , maxi = 0;

        // unordered_map<int , int> freq1 , freq2;

        // for(int i : nums){
        //     freq1[i]++;
        //     deg = max(deg , freq1[i]);
        // }

        // int i = 0 , mini = INT_MAX;

        // for(int j = 0 ; j < nums.size() ; j++){
        //     freq2[nums[j]]++;

        //     maxi = max(maxi , freq2[nums[j]]);

        //     while(maxi >= deg){
        //         mini = min(mini , j-i+1);

        //         freq2[nums[i]]--;

        //         maxi = INT_MIN;

        //         for(auto [num , f] : freq2){
        //             maxi = max(maxi , f);
        //         }
        //         i++;
        //     }
        // }

        // return mini;

        // Approach 2 - optimal --> we need to find minimum length of the window with maximum freq == deg , so instead of expanding and shrinking the window , just calculate first and last position of all the element , and the element with frequency == deg , just calculate the length of that window

        unordered_map<int , int> freq , firstPos , lastPos;
        int n = nums.size() , deg = 0;
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
            deg = max(deg , freq[nums[i]]);

            if(!firstPos.count(nums[i])){
                firstPos[nums[i]] = i;
            }

            lastPos[nums[i]] = i;
        }

        int mini = INT_MAX;

        for(auto [num , f] : freq){
            if(f == deg){
                mini = min(mini , lastPos[num] - firstPos[num] + 1);
            }
        }

        return mini;
    }
};