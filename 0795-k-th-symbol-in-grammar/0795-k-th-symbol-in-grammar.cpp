#define ll long long
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k == 1) return 0;

        ll len = 1;
        ll newK = -1;

        for(int i = 1 ; i < n ; i++){
            if(len >= k){
                break;
            }
            len *= 2; 
        }

        newK = k - len/2;

        int c = kthGrammar(n-1 , newK);

        return !c;
    }
};