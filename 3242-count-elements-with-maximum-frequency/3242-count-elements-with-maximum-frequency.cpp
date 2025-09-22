class Solution {
public:
    // 1 -> 2 , 2 -> 2 , 3 -> 1 , 4 -> 1
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int> freq;

        for(int i : nums){
            freq[i]++;
        }
        int maxi = INT_MIN;
        int cnt = 0;
        for(auto [num , f] : freq){
            if(f > maxi){
                maxi = f;
                cnt = 1;
            }else if(f == maxi) cnt++;

        }

        return maxi*(cnt);
    }
};