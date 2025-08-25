class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        // logic is as each element in nums be assigned to exactly one group , so mininum number of groups i need to make will be equal to the element with highest frequency 

        vector<int> freq(1e5 + 1 , 0);

        int numG = 0 , numE = 0;

        for(int i : nums) freq[i]++;

        for(int i = 1 ; i <= 1e5 ; i++){
            numG = max(numG , freq[i]);
        }

        int totalEle = numG * k;

        if(nums.size() < totalEle) return false;

        return (nums.size() % k == 0);
    }
};