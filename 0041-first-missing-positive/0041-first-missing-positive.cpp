class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            brute force approach --> O(n logn)  

            int p = 4

            [3 , 0, 4 , -1 , 1]  --> [-1 ,0 , 1 , 2, 3]

            better approach --> O(n) and O(n)

            n --> [1 , n+1]
            n = 4
            [1 , 2 , 1000, 4] --> 5

            unordered_set<int> st(nums.begin() , nums.end());

            for(int i = 1 ; i <= n ; i++){
                if()
            }

            optimal approach --> O(n) and O(1)
        */

        unordered_set<int> st(nums.begin() , nums.end());

        for(int i = 1 ; i <= nums.size() ; i++){
            if(!st.count(i)) return i;
        }

        return nums.size() + 1; 
    }
};