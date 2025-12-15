class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch == 'u');
    }

    string reverseWords(string s) {
        int cnt1 = 0 , cnt2 = 0;

        s += " ";

        int i = 0;

        while(s[i] != ' '){
            if(isVowel(s[i])) cnt1++;i++;
        }

        i++;

        while(i < s.length()){
            int j = i;

            while(j < s.length() && s[j] != ' '){
                if(isVowel(s[j])) cnt2++;
                j++;
            }

            if(cnt1 == cnt2){
                // flag = true;
                int p1 = i , p2 = j - 1;
            
                while(p1 <= p2){
                    swap(s[p1] , s[p2]);
                    p1++;p2--;
                }
            }

            i = j;
            i++;

            cnt2 = 0;
        }

        s.pop_back();

        return s;
    }
}; 
