class RandomizedSet {
    unordered_set<int> us;
    int n;
public:
    RandomizedSet() {
        n=0;
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(us.find(val) == us.end()){
            us.insert(val);
            n++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(us.find(val) != us.end()){
            us.erase(val);
            n--;
            return true;
        }
        return false;  
    }    
    
    int getRandom() {
        int index =  (rand()%n);
        auto itr = us.begin();
        advance(itr, index);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */