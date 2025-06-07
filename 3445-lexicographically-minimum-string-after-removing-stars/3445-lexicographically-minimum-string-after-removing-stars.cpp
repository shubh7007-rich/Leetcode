class Solution {
public:
    string clearStars(string s) {

        /* 
            cmp -
                for example if cmp has a return statement like (return a < b) , so if it returns true
                that means a has less priority than b it will remain below b in the heap 
                so a < b will be used to define a max-heap
                and a > b will be used to define a min-heap
        */

        // using pii = pair<int ,int>;
        // auto cmp = [](pii & a , pii & b){
        //     if(a.first == b.first){
        //         return a.second < b.second;    
        //     }

        //     return a.first > b.first;
        // };

        int n = s.length();    

        // priority_queue<pii , vector<pii> , decltype(cmp)> pq;

        vector<vector<int>> ind(26 , vector<int>());
        priority_queue<char , vector<char> , greater<char>> pq;

        vector<int> marked(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '*'){
                marked[i] = 1;

                if(!pq.empty()){
                    auto p = pq.top();
                    pq.pop();

                    int idx = ind[p-'a'].back();
                    ind[p-'a'].pop_back();

                    marked[idx] = 1;
                }
            }else{
                pq.push(s[i]);
                ind[s[i]-'a'].push_back(i);
            }
        }
        string str = "";

        for(int i = 0 ;i  < n ; i++){
            if(!marked[i]){
                str += s[i];
            }
        }

        return str;
    }
}; 