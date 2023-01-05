class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        int count = 0;
        
        for(int i = 2; i <= sqrt(n); i++){
            if(prime[i]){
                for(int j = i*i; j < n; j=j+i){
                    prime[j] = false;
                }
            }
        }
        for(int j = 2; j < n; j++){
            if(prime[j])
                count++;
        }
        return count;
    }
};