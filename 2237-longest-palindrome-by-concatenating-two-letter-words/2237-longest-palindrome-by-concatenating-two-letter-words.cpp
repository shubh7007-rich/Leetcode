class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string , int> mp;

        for(string & str : words){
            mp[str]++;
        }

        int cnt = 0 , flag = 0 , maxi = 0;

        auto it = mp.begin();

        while(it != mp.end()){
            string str = it->first;
            int freq = it->second;
            string temp = str;
            reverse(temp.begin() , temp.end());

            if(str[0] == str[1]){
                maxi = max(maxi , 2*mp[str]);

                cnt += (freq - (freq%2)) * 2;

                if(freq%2) flag = 1;
            }else{
                if(mp.find(temp) != mp.end()){
                    int x = min(freq , mp[temp]);
                    x *= 2;

                    cnt += (2*x);

                    mp[temp] = 0;
                }
            }
           mp[str] = 0;
           ++it;
        } 

        if(flag) cnt += 2;

        return (cnt > maxi) ? cnt : maxi;
    }
};