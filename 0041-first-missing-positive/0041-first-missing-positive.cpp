class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            brute force approach --> O(n log n)

            better approach --> O(n) and O(n)



        
        */

        unordered_set<int> st(nums.begin() , nums.end());

        for(int i = 1 ; i < 100001 ; i++){
            if(!st.count(i)) return i;
        }

        return 100001;
        
    }
};