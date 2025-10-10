class MyHashMap {
public:
    /*
        1e6 + 1
    */

    vector<int> cont;
    MyHashMap() {
        cont = vector<int>(1000001 , -1);    
    }
    
    void put(int key, int value) {
        cont[key] = value;
    }
    
    int get(int key) {
        return cont[key];
    }
    
    void remove(int key) {
        cont[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */