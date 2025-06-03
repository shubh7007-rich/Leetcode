class Solution {
public:
   
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin() , wordDict.end());

        queue<int> que;

        int n = s.length();

        vector<int> vis(n , 0);

        que.push(0);

        while(!que.empty()){
            int start = que.front();
            que.pop();

            if(start == s.length()) return true;

            for(int end = start ; end < s.length() ; end++){

                if(vis[end]) continue;

                if(st.find(s.substr(start , end - start + 1)) != st.end()){
                    que.push(end+1);
                    vis[end] = 1;
                }
            }

        }


        return false;
    }
};