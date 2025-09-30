class Solution {
public:
    /*
        ((()()))()  
        (*))

    */
    int dp[100][101];

    bool func(int ind , int cnt , string & s){
        if(ind >= s.length()){
            if(cnt == 0) return true;

            return false;
        }
        if(cnt < 0) return false;

        if(dp[ind][cnt] != -1) return dp[ind][cnt];

        if(s[ind] == '('){
            if(dp[ind][cnt] = func(ind + 1 , cnt + 1 , s)) return true;
        }else if(s[ind] == ')'){
            if(dp[ind][cnt] = func(ind + 1 , cnt - 1 , s)) return true;
        }else{
            return dp[ind][cnt] =  (func(ind + 1 , cnt , s) | func(ind + 1 , cnt+1 , s) | func(ind + 1 , cnt-1 , s));
        }

        return false;
    }

    bool checkValidString(string s) {
        memset(dp , -1 , sizeof(dp));

        return func(0 , 0 , s);
    }
};