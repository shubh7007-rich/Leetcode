class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return 0;

        queue<string> que;

        que.push(beginWord);

        int lvl = 1;

        unordered_set<string> vis;

        vis.insert(beginWord);

        while (!que.empty()) {
            int size = que.size();

            while (size--) {
                string fro = que.front();
                que.pop();

                for (int i = 0; i < fro.length(); i++) {
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        string temp = fro;
                        temp[i] = ch;

                        if (st.find(temp) != st.end() &&
                            (vis.find(temp) == vis.end())) {
                            if (temp == endWord)
                                return lvl+1;
                            que.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }

            lvl++;
        }

        return 0;
    }
};