class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26 , -1) , last(26 , -1);

        for(int i = 0 ; i < s.length() ; i++){
            if(first[s[i] - 'a'] == -1){
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        int cnt = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(first[i] == -1) continue;
            set<char> st;
            for(int m = first[i]+1 ; m < last[i] ; m++){
                st.insert(s[m]);
            }
            cnt += st.size();
        }

        return cnt;
    }
};