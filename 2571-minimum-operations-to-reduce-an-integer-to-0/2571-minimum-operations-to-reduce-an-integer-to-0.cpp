class Solution {
public:
    int minOperations(int n) {
        int op = 0, i = 1;
        
        while(n > 0){
            int n1 = n;
            i = 1;
            while(n1 - pow(2, i) > 0){
                i++;
            }
            if(n1 - pow(2, i-1) > pow(2, i) - n1)
                n = pow(2, i) - n1;
            else
                n = n1 - pow(2, i-1);
            op++;
        }
        return op;
    }
};