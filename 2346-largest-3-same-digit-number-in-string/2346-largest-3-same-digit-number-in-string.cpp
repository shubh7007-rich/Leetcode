class Solution {
public:
    string largestGoodInteger(string num) {
        int i = 0;
        unordered_map<char , int> mp;
        string maxi = "";

        for(int j = 0 ; j < num.length() ; j++){
            mp[num[j]]++;

            while(i < j  && ((mp.size() > 1) || (j-i+1 > 3))){
                mp[num[i]]--;

                if(mp[num[i]] == 0){
                    mp.erase(num[i]);
                }

                i++;
            }

            if(j-i+1 == 3){
                maxi = max(maxi , num.substr(i , j-i+1));
            }
        }

        return maxi;
    }
};