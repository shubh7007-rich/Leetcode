class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, int> mp;
        unordered_map<string , int> vo;

        int ind = 0;
        for (auto& wr : wordlist) {
            exact.insert(wr);

            string temp2 = wr;

            for (char& ch : temp2) {
                ch = tolower(ch);
            }

            if(!mp.count(temp2)){
                mp[temp2] = ind;
            }

            for(char & ch : temp2){
                if(isVowel(ch)){
                    ch = '*';
                }
            }

            if(!vo.count(temp2)){
                vo[temp2] = ind;
            }

            ind++;
        }

        vector<string> ans;

        for (string& str : queries) {
            if (exact.count(str)) {
                ans.push_back(str);
            } else {
                bool flag = false;

                string temp = str;

                for (char& ch : temp) {
                    ch = tolower(ch);
                }

                // for (string& s : wordlist) {
                //     string temp2 = s;

                //     for (char& ch : temp2) {
                //         ch = tolower(ch);
                //     }

                //     if (temp == temp2) {
                //         ans.push_back(s);
                //         flag = true;
                //         break;
                //     }
                // }

                if(mp.count(temp)){
                    ans.push_back(wordlist[mp[temp]]);
                    continue;
                }

                bool flag2 = false;
               
                    // for (string& s : wordlist) {
                    //     string temp2 = s;

                    //     if (temp.length() != temp2.length())
                    //         continue;

                    //     for (char& ch : temp2) {
                    //         ch = tolower(ch);
                    //     }
                    //     bool mila = true;
                    //     for (int i = 0; i < temp.length(); i++) {
                    //         if (temp2[i] != temp[i]) {
                    //             if (!isVowel(temp2[i]) || !isVowel(temp[i])) {
                    //                 mila = false;
                    //                 break;
                    //             }
                    //         }
                    //     }

                    //     if (mila) {
                    //         ans.push_back(s);
                    //         flag2 = true;
                    //         break;
                    //     }
                    // }

                    for(char & ch : temp){
                        if(isVowel(ch)){
                            ch = '*';
                        }
                    }

                    if(vo.count(temp)){
                        ans.push_back(wordlist[vo[temp]]);
                        flag2 = true;
                    }
                

                if (!flag2) {
                    ans.push_back("");
                }
            }
        }

        return ans;
    }
};