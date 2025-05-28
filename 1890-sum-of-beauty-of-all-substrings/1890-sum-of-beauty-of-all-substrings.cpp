class Solution {
public:
    int beautySum(string s) {
        int sum = 0;

        for(int i = 0 ; i < s.length() ; i++){
            vector<int> freq(26 , 0);
            for(int j = i ; j < s.length() ; j++){
                freq[s[j]-'a']++;
                int mini = INT_MAX , maxi = INT_MIN;
                for(int e = 0 ; e < 26 ; e++){
                    if(freq[e] > 0){
                        if(freq[e] > maxi){
                        maxi = freq[e];
                    }
                    if(freq[e] < mini){
                        mini = freq[e];
                    }
                    }
                    
                }
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};