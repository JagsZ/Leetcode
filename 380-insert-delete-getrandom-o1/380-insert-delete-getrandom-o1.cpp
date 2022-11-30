class RandomizedSet {
    vector<int> val_index;
    unordered_map<int, int> map;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) != map.end()){
            return false;
        }
        map[val] = val_index.size();
        val_index.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val) != map.end()){
            int last = val_index[val_index.size()-1];
            int index = map[val];
            swap(val_index[index], val_index[val_index.size()-1]);
            map[last] = index;
            map.erase(val);
            val_index.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int ran = rand() % val_index.size();
        return val_index[ran];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */