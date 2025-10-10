class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> st(nums.begin() , nums.end());
        int maxi = 0;
        for(int i : st){
            if(st.count(i-1)) continue;
            int cnt = 1 , num = i;
            while(st.count(num+1)){
                cnt++;
                num = num + 1;
            }
            maxi = max(maxi , cnt);
        }

        return maxi;
    }
};