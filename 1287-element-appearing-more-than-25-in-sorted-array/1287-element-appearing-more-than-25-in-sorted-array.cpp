class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size(), count = 1;
        
        for(int i = 1; i < len; i++){
            if(arr[i-1] == arr[i]){
                count++;
                if(count > len/4)
                    return arr[i];
            }
            else{
                count = 1;
            }
        }
        return arr[0];
    }
};