class MyHashMap {
int prime=2069;
vector<list<pair<int,int>>> hash;
public:
    pair<int,int> find(list<pair<int,int>> &val, int key){
        pair<int,int> ans={INT_MAX,INT_MAX};
        for(auto x : val){
            if(x.first == key)
                ans=x;
        }
        return ans;
    }
    
    MyHashMap() {
        list<pair<int,int>> val;
        for(int i=0; i<prime; i++){
            hash.push_back(val);
        }
    }
    
    void put(int key, int value) {
        int hash_key = key%prime;
        list<pair<int,int>> val = hash[hash_key];
        val.push_front({key, value});
        hash[hash_key]=val;
    }
    
    int get(int key) {
        int hash_key = key%prime; 
        list<pair<int,int>> val = hash[hash_key];
        for(auto x:val){
            if(x.first == key)
                return x.second;
        }
        return -1;
    }
    
    void remove(int key) {
       int hash_key = key%prime; 
       list<pair<int,int>> val = hash[hash_key];
       if(val.empty())
           return;
       while(!val.empty()){
           pair<int,int> data = find(val,key);
           if(data.first == INT_MAX && data.second == INT_MAX)
               break;
           val.remove(data);
       }
       hash[hash_key]=val;
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */