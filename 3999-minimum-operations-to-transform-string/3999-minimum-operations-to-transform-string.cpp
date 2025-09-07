class Solution {
public:
    int minOperations(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        int cnt = 0;

        while (true) {
            bool flag = true;

            for (int i = 0; i < 26; i++) {
                char ch1 = 'a' + i;

                if (ch1 == 'a')
                    continue;

                if (freq.count(ch1)) {
                    char ch2 = ch1 + 1;

                    if(ch1 == 'z') ch2 = 'a';

                    freq[ch2] += freq[ch1];

                    freq.erase(ch1);

                    flag = false;

                    cnt++;
                }
            }

            if(flag) break;
        }

        return cnt;
    }
};