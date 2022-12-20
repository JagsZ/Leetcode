class KthLargest {
    int kth = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto x : nums)
            pq.push(x);
        
        //while(pq.size() > kth){
          //  pq.pop();
        //}
        
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > kth){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */