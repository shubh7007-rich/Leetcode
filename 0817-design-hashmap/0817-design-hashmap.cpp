class MyHashMap {
public:

    int M;
    vector<list<pair<int , int>>> vec;

    int getInd(int key){
        return key % M;
    }

    /*
        hash(int key) return key % 10;
        5 31
        105 % 100 --> 5

        open addressing  --> linear probing and quadratic probing  +(1)^2 +(2)^2 ......


        separate chaining --> we will be using this
        5 1  --> 35 3  --> 75 2 

        0  1 2 3 4  5   6     7
                   5,1 35,3 75,2
    */

    MyHashMap() {
        M = 15000;
        vec = vector<list<pair<int , int>>>(M , list<pair<int , int>>{});
    }
    
    void put(int key, int value) {
        int idx = getInd(key);

        auto & chain = vec[idx];
        bool flag = false;
        for(auto & p : chain){
            if(p.first == key){
                p.second = value;
                flag = true;
                break;
            }
        }

        if(!flag){
            chain.push_back({key , value});
        }
    }
    
    int get(int key) {
        int idx = getInd(key);

        auto & chain = vec[idx];

        for(auto & p : chain){
            if(p.first == key){
                return p.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int idx = getInd(key);

        auto & chain = vec[idx];

        for(auto it = chain.begin() ; it != chain.end() ; ++it){
            if(it->first == key){
                chain.erase(it);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */