class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        /*
        Approach 1 -- O(n) , S.C - O(n)
        vector<int> temp;

        for(int i = 0 ; i < nums.size() ; i++){
            if(temp.empty()){
                temp.push_back(nums[i]);
            }else{
                if(nums[i] != temp.back()){
                    temp.push_back(nums[i]);
                }
            }
        }

        for(int i = 0 ; i < temp.size() ; i++){
            nums[i] = temp[i];
        }
        return temp.size();

        */

        // Approach 2 -- O(n) , O(1)

        int curr = 1;

        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }else{
                nums[curr] = nums[i];
                curr++;
            }
        }

        return curr;
    }
};