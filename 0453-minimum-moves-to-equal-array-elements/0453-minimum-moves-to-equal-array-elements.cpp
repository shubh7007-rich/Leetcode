#define ll long long

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // [1 , 2, 3]     ----->   [4 , 4, 4]

        // suppose we need m moves to make all elements equal

        // 1st observation -->  1 + 3 = 4

        //                    1st eq --> mini + m = x  

        // 2nd observation -->      n * x = intialSum + m * (n-1) 

        //                         n * (mini + m) = intialSum + m * n - m
        //                         n * mini + n*m = intialSum + m*n - m
        //                         m = intialSum - n * mini

        int intialSum = accumulate(nums.begin() , nums.end() , 0);

        int mini = *min_element(nums.begin() , nums.end());

        return intialSum - nums.size() * mini;


    }
};