class MyHashMap {
private:
    // A prime number is a good choice for the size to help distribute keys more
    // evenly.
    const int size = 10007;
    // Our main storage: a vector where each element is a linked list (chain).
    std::vector<std::list<std::pair<int, int>>> buckets;

    /** A simple hash function to map a key to a bucket index. */
    int hash(int key) { return key % size; }

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        // Initialize the vector with 'size' empty linked lists.
        buckets.resize(size);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        // Get a reference to the specific chain for this index.
        auto& chain = buckets[index];

        // Check if the key already exists in the chain.
        for (auto& pair : chain) {
            if (pair.first == key) {
                // If it exists, update the value and return.
                pair.second = value;
                return;
            }
        }
        // If the key doesn't exist, add the new pair to the chain.
        chain.push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        // Get a const reference as we are only reading.
        const auto& chain = buckets[index];

        // Search for the key in the chain.
        for (const auto& pair : chain) {
            if (pair.first == key) {
                // Key found, return its value.
                return pair.second;
            }
        }
        // If the loop finishes, the key was not found.
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key) {
        int index = hash(key);
        auto& chain = buckets[index];

        // Use the remove_if list method with a lambda to find and erase the
        // element. This is a clean and efficient way to remove an item from a
        // std::list.
        chain.remove_if([key](const auto& pair) { return pair.first == key; });
    }
};
// auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */