class SmallestInfiniteSet {
    unordered_set<int> set;
    priority_queue<int, vector<int>, greater<int>> pq;
    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        int ans;
        if(!pq.empty()){
            ans = pq.top();
            pq.pop();
            set.erase(ans);
        }else{
            ans = curr;
            curr += 1;
        }
        return ans;
    }
    
    void addBack(int num) {
        if(curr <= num || set.count(num)){
            return;
        }
        pq.push(num);
        set.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */