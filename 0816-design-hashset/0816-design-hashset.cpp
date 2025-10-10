class MyHashSet {
public:
    
    vector<bool> vec;

    MyHashSet() {
        int n = 1e6 + 1;
        vec.resize(n , false);
    }
    
    void add(int key) {
        vec[key] = true;
    }
    
    void remove(int key) {
        vec[key] = false;
    }
    
    bool contains(int key) {
        return vec[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */