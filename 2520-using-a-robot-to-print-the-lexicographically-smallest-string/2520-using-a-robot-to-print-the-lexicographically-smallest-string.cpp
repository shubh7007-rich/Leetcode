class Solution {
public:
    string robotWithString(string s) {
        map<char, int> mp;
        for (char ch : s) mp[ch]++;

        string t = "", ans = "";

        for (int i = 0; i < s.length(); ++i) {
            char curr = s[i];
            t.push_back(curr);
            mp[curr]--;
            if (mp[curr] == 0) mp.erase(curr);

            // Pop as many chars from stack t if they are <= smallest remaining
            while (!t.empty() && (mp.empty() || t.back() <= mp.begin()->first)) {
                ans += t.back();
                t.pop_back();
            }
        }

        return ans;
    }
};
