class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        if(nums.empty()) return 0;

        int cnt = 1, maxi = 1;

        for(int & i : nums) st.insert(i);

        for(auto i : st){
            if(!st.count(i-1)){
                int x = i+1;

                while(st.count(x)){
                    cnt++;
                    x = x + 1;
                }

                maxi = max(maxi , cnt);

                cnt = 1;
            }
        }

        return maxi;
    }
};