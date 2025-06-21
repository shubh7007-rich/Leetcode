class Solution {
public:
    int maxDistance(string str, int k) {
        // unordered_map<char , int> mp;
        // int maxi = 0;
        // mp['E'] = 0;
        // mp['W'] = 0;
        // mp['N'] = 0;
        // mp['S'] = 0;
        int n = 0 , s = 0 , e = 0 , w = 0;
        int i = 1 , maxi = 0;
        for(char & ch : str){
            if(ch == 'N')n++;
            if(ch == 'S')s++;
            if(ch == 'E')e++;
            if(ch == 'W')w++;
            // pair N S ko convert krde
            
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