class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int num1 = num;
            int num2 = 0;
            while(num1 > 0){
                num2 += (num1 % 10);
                num1 /= 10;
            }
            num = num2;
        }
        return num;
    }
};