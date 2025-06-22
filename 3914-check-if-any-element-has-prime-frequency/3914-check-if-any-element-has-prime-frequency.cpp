class Solution {
public:
    bool isPrime(int n){
        int cnt = 0;
        if(n == 1) return false;

        for(int i = 2 ; i * i <= n ; i++){
            if(n%i == 0)return false;
        }

        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int , int> freq;

        for(int & i : nums) freq[i]++;

        for(auto [num , f] : freq){
            if(isPrime(f)) return true;
        }

        return false;
    }
};