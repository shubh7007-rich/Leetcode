class Solution {
public:
    int maxDistance(string s, int k) {
        map<char , int> mp;
        int maxi = 0;
        mp['E'] = 0;
        mp['W'] = 0;
        mp['N'] = 0;
        mp['S'] = 0;
        int i = 1;
        for(char & ch : s){
            mp[ch]++;
            // pair N S ko convert krde
            int n = mp['N'] , s = mp['S'] , e = mp['E'] , w = mp['W'];
            int c1 = min(n , s);

            int t1 = k - min(c1 , k);

            int conv1 = min(c1 , k);

            int conv2 = 0;

            if(t1 > 0){
                int c2 = min(e , w);

                int t2 = k - min(c2 , t1);

                conv2 = min(c2 , t1);
            }

            maxi = max(maxi , abs(n-s) + 2*conv1 + abs(e-w) + 2*conv2);
            i++;
        }

        return maxi;
    }
};