class Solution {
public:
    bool isPalindrome(string & str){
        int l = 0 , r = str.length()-1;
        while(l <= r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length() , maxi = 0;
        string ans = "";
        for(int i = 0 ; i < n; i++){
            int l = i , r = i;

            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    if((r-l+1) > maxi){
                        maxi = r-l+1;
                        ans = s.substr(l , r-l+1);
                    }
                }else{
                    break;
                }
                l--;r++;
            }

            // even

            l = i , r = i+1;

            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    if(maxi < (r-l+1)){
                        maxi = r-l+1;
                        ans = s.substr(l , r-l+1);
                    }
                }else{
                    break;
                }
                l--;
                r++;
            }
        }

        return ans;

    }
};