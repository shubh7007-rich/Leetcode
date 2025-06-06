class Solution {
public:
    string robotWithString(string s) {
        map<char , int> mp;

        for(char ch : s) mp[ch]++;

        string t = "" , ans = "";

        for(int i = 0; i < s.length() ; i++){
            while((!t.empty() && (t.back() <= mp.begin()->first))){
                ans += t.back();
                t.pop_back();
            }
            t.push_back(s[i]);
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
        }

        while(!t.empty()){
            ans.push_back(t.back());
            t.pop_back();
        }  

        return ans;
    }
};