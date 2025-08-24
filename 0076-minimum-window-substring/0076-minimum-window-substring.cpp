class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq1(128, 0), freq2(128, 0);

        int validS = -1, validE = -1;

        for (char ch : t) {
            freq2[ch]++;
        }

        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            freq1[s[j]]++;

            bool flag = true;

            for (int k = 0; k < 128; k++) {
                if (freq1[k] < freq2[k]) {
                    flag = false;
                    break;
                }
            }

            if (flag == true) {
                while (true) {
                    bool f = true;

                    if((j-i+1 < validE - validS + 1) || (validS == -1)) {
                        validS = i, validE = j;
                    }

                    freq1[s[i]]--;
                    i++;

                    for (int k = 0; k < 128; k++) {
                        if (freq1[k] < freq2[k]) {
                            f = false;
                            break;
                        }
                    }

                    if(!f) break;
                }
            }
        }

        if(validS == -1) return "";

        return s.substr(validS , validE - validS + 1);
    }
};