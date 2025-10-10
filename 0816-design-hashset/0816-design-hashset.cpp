class MyHashSet {
public:
    /*  
        we are going to use hashing , hashing is a techinque by which we map large number of key values into a smaller space
        Open addressing(linear probing and quadratic probing) and separate chaining

        here we are going to use separate chaining , in separate chaiing we don't store just a single value in a bucket instead we store list in each bucket


    */

    int M;   // size of our container i.e vector of list

    vector<list<int>> hashSet;

    int getInd(int key){
        return key % M;
    }

    MyHashSet() {
        M = 1000;
        hashSet = vector<list<int>>(M , list<int>{});
    }
    
    void add(int key) {
        int idx = getInd(key);

        auto itr = find(hashSet[idx].begin() , hashSet[idx].end() , key);

        if(itr == hashSet[idx].end()){
            hashSet[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = getInd(key);

        auto itr = find(hashSet[idx].begin() , hashSet[idx].end() , key);

        if(itr != hashSet[idx].end()){
            hashSet[idx].erase(itr);
        }
    }
    
    bool contains(int key) {
        int idx = getInd(key);

        auto itr = find(hashSet[idx].begin() , hashSet[idx].end() , key);

        return itr != hashSet[idx].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */