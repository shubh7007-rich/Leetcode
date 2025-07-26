class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size()  , maxi = 1 , cnt = 1;

        if(n == 0) return 0;
        
        vector<int> temp(n , INT_MAX);

        set<int> st(nums.begin() , nums.end());

        auto it = st.begin();
        auto prev = it;
        it = next(it);

        while(it != st.end()){
            if(*prev + 1 == *it){
                cnt++;
                maxi = max(cnt , maxi);
            }else{
                cnt = 1;
            }
            prev = it;
            it = next(it);
        }

        return maxi;
    }
}; 