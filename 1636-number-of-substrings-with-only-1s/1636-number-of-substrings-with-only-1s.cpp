class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
        unordered_map<int , int> mp;

        int cnt = 0;

        for(char & ch : s){
            if(ch == '0'){
                mp.clear();
            }else{
                mp[ch]++;
            }

            if(!mp.empty()){
                cnt = (cnt + (mp['1']) % mod) % mod;
            }
        }

        return cnt % mod;
    }
};