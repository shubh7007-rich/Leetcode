class Solution {
public:
    // s = aabdc   t = abc
    /*
     brute force approach 
        string ans ="";
        int n = s.length() , mini = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                // string str = s.substr(i , j-i+1);
                vector<int> marked(n , 0);
                bool flag = true;
                for(char ch : t){
                    bool milgya = false;
                    for(int k = i ; k <= j ;k++){
                        if(s[k] == ch && !marked[k]){
                            milgya = true;
                            marked[k] = 1;
                            break;
                        }
                    }

                    if(!milgya){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    if(mini > j-i+1){
                        mini = j-i+1;
                        ans = s.substr(i , j-i+1);
                    }
                }

            }
        }

        return ans;*/

    string minWindow(string s, string t) {
        vector<int> freqS(128 , 0) , freqT(128 , 0);

        int i = 0  , n = s.length() , mini = INT_MAX; 

        string ans = "";

        for(char ch : t) freqT[ch]++;

        for(int j = 0 ; j < n ; j++){
            freqS[s[j]]++;

            while(i < j && freqS[s[i]] > freqT[s[i]]){
                freqS[s[i]]--;
                i++;
            }

            bool flag = true;

            for(int i = 65 ; i < 123 ; i++){   // A - 65 , a - 97 , z - 122 
                if(freqS[i] < freqT[i]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                if(mini > j-i+1){
                    mini = j-i+1;
                    ans = s.substr(i , j-i+1);
                }
            }
        }

        return ans;
    }
};