#define hash_mode 2069
class MyHashSet {
    vector<list<int>> hashSet;
public:
    bool isNotFound(list<int> l, int key){
        for(auto x : l){
            if(x == key)
                return false;
        }
        return true;
    }
    
    MyHashSet() {
        list<int> val;
        for(int i=0; i<hash_mode; i++){
            hashSet.push_back(val);
        }
    }
    
    void add(int key) {
        int index = key % hash_mode;
        if(isNotFound(hashSet[index], key)){
            hashSet[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = key % hash_mode;
         hashSet[index].remove(key);
    }
    
    bool contains(int key) {
        int index = key % hash_mode;
        return !isNotFound(hashSet[index], key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */