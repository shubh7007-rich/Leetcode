class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length(), maxi = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
           
           // odd 
           int l = i , r = i;

           while(l >= 0 && r < n){
                if(s[l] != s[r]) break;
                l--;
                r++;
           }
           l++;r--;
           if(r-l+1 > maxi){
                ans = s.substr(l , r-l+1);
                maxi = r-l+1;
           }

           // even 
           l = i , r = i+1;

           while(l >= 0 && r < n){
                if(s[l] != s[r]) break;
                l--;
                r++;
           }
           l++;r--;
           if(r-l+1 > maxi){
                ans = s.substr(l , r-l+1);
                maxi = r-l+1;
           }
        }

        return ans;
    }
};