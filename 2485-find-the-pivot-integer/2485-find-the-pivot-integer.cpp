class Solution {
public:
    int pivotInteger(int n) {
        int i = 1;
        int j = n;
        int left_sum = i;
        int right_sum = j;
        while(i != j){
            if(left_sum < right_sum){
                i++;
                left_sum += i;
            }else{
                j--;
                right_sum += j;
            }
        }
        if(left_sum == right_sum){
            return i;
        }
        return -1;
    }
};