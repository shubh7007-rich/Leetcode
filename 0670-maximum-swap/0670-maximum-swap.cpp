class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);

        for(int i = 0 ; i < str.size() ; i++){
            bool swapp = false;
            char mini = str[i];
            int idx = -1;
            for(int j = i + 1 ; j < str.size() ; j++){
                if(str[j] >= mini){
                    idx = j;
                    mini = str[j];
                }
            }
            if(mini == str[i]) continue;
            if(idx != -1){
                swap(str[i] , str[idx]);
                swapp = true;
            }

            if(swapp) break;
        }

        return stoi(str);
    }
};