class Solution {
public:
    // bool isPos(int mid , vector<int>& cit){
    //     int c = 0;

    //     for(int i = 0 ; i < cit.size() ; i++){
    //         if(cit[i] >= mid) c++;
    //     }

    //     return c >= mid;
    // }
    int hIndex(vector<int>& cit) {
        sort(cit.begin() , cit.end());

        int n = cit.size();

        int l = 0 , r = n-1, ans = 0;

        while(l <= r){
            int mid = (l+r)/2;

            int issJada = n - mid;

            if(cit[mid] >= issJada){
                ans = issJada; 
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};