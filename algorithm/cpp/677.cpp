class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        storage[key] = val;
    }
    
    int sum(string prefix) {
        int rtn = 0;
        for (auto iter : storage) {
            if (iter.first.rfind(prefix, 0) == 0) {
                rtn = rtn + iter.second;
            }
        }
        return rtn;
    }
    
    unordered_map<string, int> storage;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */