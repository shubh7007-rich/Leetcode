class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;

        while(num){
            arr.push_back(num % 10);
            num = num / 10;
        }

        for(int i = arr.size() - 1; i >= 0 ; i--){
            if(arr[i] != 9){
                arr[i] = 9;
                break;
            }
        }


        int ans = 0;

        for(int i = arr.size() - 1; i >= 0 ; i--){
            ans = ans * 10 + arr[i];
        }

        return ans;
    }
};