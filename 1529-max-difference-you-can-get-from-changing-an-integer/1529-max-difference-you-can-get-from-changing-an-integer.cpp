class Solution {
public:
    int maxDiff(int num) {
        vector<int> arr;

        while(num){
            arr.push_back(num%10);
            num /= 10;
        }

        reverse(arr.begin() , arr.end());

        int n = arr.size();

        set<int> st;
        vector<int> processed(10 , 0);

        for(int i = 0 ; i < n ; i++){
            int dig = arr[i];

            if(processed[dig]) continue;

            for(int j = 0 ; j < 10 ; j++){
                int gen = 0;
                if(arr[0] == dig && j == 0) continue;
                
                for(int k = 0 ; k < n ; k++){
                    if(arr[k] == dig){
                        
                        gen = gen * 10 + j;
                    }else{
                        gen = gen * 10 + arr[k];
                    }
                }
                st.insert(gen);
            }

            processed[dig] = 1;
        }
        auto it = st.begin();
        while(*it == 0){
            it++;
        }

        auto last = st.rbegin();

        cout << *it << " " << *last;

        return *last - *it;
        
    }
};