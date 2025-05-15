class MyHashMap {
private:
    static const int SIZE = 1000;
    vector<list<pair<int, int>>> table;

int hash(int key) {
    return (key % SIZE);
}

public:
    MyHashMap() {
        table.resize(SIZE);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        for(auto& [k, v] : table[index]) {
            if(k == key) {
                v = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        for(auto& [k,v] : table[index]) {
            if(k == key) {
                return v;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        for(auto it = table[index].begin(); it != table[index].end(); it++) {
            if(it->first == key) {
                table[index].erase(it);
                return;
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