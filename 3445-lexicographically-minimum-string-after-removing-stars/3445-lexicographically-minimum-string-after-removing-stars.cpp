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

        using pii = pair<int ,int>;
        auto cmp = [](pii & a , pii & b){
            if(a.first == b.first){
                return a.second < b.second;    
            }

            return a.first > b.first;
        };

        int n = s.length();    

        priority_queue<pii , vector<pii> , decltype(cmp)> pq;

        vector<int> marked(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '*'){
                marked[i] = 1;

                if(!pq.empty()){
                    auto p = pq.top();
                    pq.pop();

                    marked[p.second] = 1;
                }
            }else{
                pq.push({s[i] , i});
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