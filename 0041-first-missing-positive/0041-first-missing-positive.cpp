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
                if(!st.count(i)) return i;
            }

            return n+1;

            optimal approach --> O(n) and O(1)

            [1 , n+1]

            [3 , 4 , 1 , 5]  

            [-3 , 4 , -1 , -5]  

            [7 , 8 , 9 , 11 , 12]

            
            [3 , -4 , 1 , 5]  

            [-3 , 1 , -1 , 1] 





        */
        int n = nums.size();

        bool contains1 = false;

        for(int i : nums){
            if(i == 1) contains1 = true;
        }

        if(!contains1) return 1;

        for(int & i : nums){
            if(i <= 0 ) i = 1;
        }

        for(int i = 0 ; i < n ; i++){
            int ind = abs(nums[i]) - 1;

            if(ind >= n) continue;

            if(nums[ind] > 0){
                nums[ind] = -nums[ind];
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0) return i+1;
        }

        return n+1;
    }
};