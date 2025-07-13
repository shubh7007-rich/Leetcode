class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int n = nums.size();

        int mid = (n/2);

        int moves = 0 , median = nums[mid];

        for(int & i : nums){
            moves += abs(median - i);
        }


        return moves;
    }
};