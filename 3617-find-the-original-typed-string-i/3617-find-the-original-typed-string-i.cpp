class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 1;
        int i = 0;
        while(i < word.length()){
            int j = i;
            int freq = 0;
            while(j < word.length()){
                if(word[j] == word[i]){
                    freq++;
                }else{
                    break;
                }
                j++;
            }
            cnt += (freq-1);
            i = j;
        }

        return cnt;
    }
};