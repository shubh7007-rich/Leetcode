class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> mpst , mpts;
        
        for(int i = 0 ; i < s.length() ; i++){
            if(mpst.count(s[i]) || mpts.count(t[i])){
                if(mpst[s[i]] != t[i]) return false;

                if(mpts[t[i]] != s[i]) return false;
            }
            mpst[s[i]] = t[i];
            mpts[t[i]] = s[i];
        }

        return true;
    }
};