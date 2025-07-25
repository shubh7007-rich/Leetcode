class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int , int> mp;
        for(int & i : nums) mp[i]++;

        for(auto [nu , freq] : mp){
            if(freq > nums.size()/2) return nu;
        }

        return -1;
    }
};