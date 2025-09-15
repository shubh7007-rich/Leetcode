class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<int , vector<int>> mp;

        int i = 0;
        for(char ch : t){
            mp[ch].push_back(i);
            i++;
        }
        int prev = -1;
        for(char ch : s){
            if(!mp.count(ch)) return false;
            bool flag = false;
            for(int num : mp[ch]){
                if(num > prev){
                    prev = num;
                    flag = true;
                    break;
                }
            }

            if(!flag) return false;
        }

        return true;
    }
};