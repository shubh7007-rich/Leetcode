class Solution {
public:
    // 3 3 --> 2 3 --> 2 2 --> 1 2 --> 1 1 -> 0 1 --> 0 0 --> Alice lose
    // 3 1 --> 

    // 2 2 --> 1 2 --> 1 1 --> alice lose
    bool winnerOfGame(string colors) {
        int cnt1 = 0 , cnt2 = 0;

        for(int i = 1 ; i < colors.size()-1 ; i++){
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A'){
                cnt1++;
            }
            if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B'){
                cnt2++;
            }
        }

        if(cnt1 > cnt2) return true;

        return false;

    }
};