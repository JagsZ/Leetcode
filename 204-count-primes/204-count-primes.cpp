class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, false);
        int count = 0;
        
        for(int i = 2; i <= sqrt(n); i++){
            int fact = i, j = 2;
            fact = i*j;
            while(fact < n){
                prime[fact] = true;
                j++;
                fact = i*j;
            }
        }
        
        for(int i = 2; i < n; i++){
            if(prime[i] == false)
                count++;
        }
        return count;
    }
};