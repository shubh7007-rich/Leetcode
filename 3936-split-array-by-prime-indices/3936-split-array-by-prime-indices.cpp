class Solution {
public:
    #define ll long long

    bool isPrime(int num){
        int cnt = 0;

        if(num <= 1) return false;

        for(int i = 2; i * i <= num ; i++){
            if(num % i == 0) cnt++;

            if(cnt >= 1) return false;
        }

        return true;
    }
    long long splitArray(vector<int>& nums) {
        ll sum1 = 0 , sum2 = 0 , n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(isPrime(i)){
                sum1 += nums[i];
            }else{
                sum2 += nums[i];
            }
        }


        return abs(sum1 - sum2);
    }
};