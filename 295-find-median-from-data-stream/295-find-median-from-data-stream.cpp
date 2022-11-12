class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.size() == 0){
            max_heap.push(num);
        }else{
            if(num >= max_heap.top()){
                min_heap.push(num);
                if(min_heap.size() > max_heap.size()){
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }
            }else{
                max_heap.push(num);
                if(max_heap.size() > min_heap.size()+1){
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                }
            }
        }
    }
    
    double findMedian() {
        double ans=0;        
        if(max_heap.size() == min_heap.size())
            ans = (max_heap.top() + min_heap.top())/2.0;
        else
            ans = max_heap.top();
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */