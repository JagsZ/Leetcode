class Solution {
    int bitCount(int n){
        int count=0;
        while(n > 0){
            if(n & 1)
                count++;
            n >>= 1;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            int count=bitCount(i);
            ans.push_back(count);
        }  
    return ans;
    }
};