class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        unordered_map<int , int> cnt;

        for(int & x : nums){
            x = (x % value + value) % value;
            cnt[x]++;
        }

        int mex = 0;

        while(true){
            int r = mex % value;

            if(cnt[r] > 0){   // that means i can produce this particular number so mex++
                cnt[r]--;
                mex++;
            }else{
                break;
            }
        }

        return mex;
    }
};