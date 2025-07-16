class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(26 , 0) , freq2(26 , 0) , ans;

        for(char ch : p) freq1[ch - 'a']++;

        int lp = p.length() , i = 0 ;


        for(int j = 0 ; j < s.length() ; j++){
            freq2[s[j]-'a']++;

            if(j-i+1 == lp){
                bool flag = true;

                for(int e = 0 ; e < 26 ; e++){
                    if(freq1[e] != freq2[e]){
                        flag = false;
                        break;
                    }
                }

                if(flag) ans.push_back(i);

                freq2[s[i]-'a']--;
                i++;
            }
        }

        return ans;
    }
};