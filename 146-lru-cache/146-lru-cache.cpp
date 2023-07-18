class LRUCache {
    public:
    class node{
        public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    unordered_map<int, node*> hash;
    int size = 0;
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(int key, int val){
        node *new_node = new node(key, val);
        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;
    }
    void delNode(node *new_node){
        node *prev_node = new_node->prev;
        node *next_node = new_node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
    
    void updateNode(node *new_node){
        node *prev_node = new_node->prev;
        node *next_node = new_node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        
        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;
        
    }
    int get(int key) {
        if(hash.find(key) != hash.end()){
            updateNode(hash[key]);
            hash[key] = head->next;
            return hash[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            delNode(hash[key]);
            addNode(key, value);
            hash[key] = head->next;
        
        }else{
            if(hash.size() < size){
                addNode(key, value);
                hash[key] = head->next;
            }else{
                hash.erase(tail->prev->key);
                delNode(tail->prev);
                addNode(key, value);
                hash[key] = head->next;
            }
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */