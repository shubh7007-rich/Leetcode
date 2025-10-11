class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*
            brute force approach --> count the frequency and the push all the elements with freq > 1

             O(n) && O(n)

            Optimal approach --> [1 , n]


            vector<int> ans;
                    [1, n]  --> size of array --> n , 3  ---> 3-1  , 1 --> 0 , n --> (n-1)
                      0  1  2  3  4  5  6  7
                     [-4,-3,-2,-7, 8, 2,-3,-1]

                     ans = 2 , 3


                     abs(-2) --> 2 --> 2-1 = 1


                     t.c --> O(n) and S.c --> O(1)

        */

        vector<int> ans;


        for(int i = 0 ; i < nums.size() ; i++){
            int ind = abs(nums[i]) - 1;

            if(nums[ind] < 0){
                ans.push_back(abs(nums[i]));
            }else{
                nums[ind] = -nums[ind];
            }
        }



        return ans;
    }
};