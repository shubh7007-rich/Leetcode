#define ll long long
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        if(k == 1) return 'a';
        
        int n = operations.size();
        ll len = 1;
        ll newK = -1;
        ll opType = -1;

        for(int i = 0 ; i < n ; i++){
            len *= 2;

            if(len >= k){
                newK = k - len/2;
                opType = operations[i];
                break;
            }
        }

        char ch = kthCharacter(newK , operations);

        if(opType == 0){
            return ch;
        }else{
            return (ch == 'z') ? 'a' : ch+1;
        }
    }
};