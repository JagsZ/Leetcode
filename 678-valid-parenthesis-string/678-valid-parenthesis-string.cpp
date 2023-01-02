class Solution {
public:
    bool checkValidString(string s) {
   
        int index = 0, left_min = 0, left_max = 0;
        
        while(index < s.length()){
            if(s[index] == '('){
                left_min++;
                left_max++;
            }else if(s[index] == '*'){
                left_min--;
                left_max++;
            }else{
                left_min--;
                left_max--;
            }
            index++;
            if(left_max < 0)
                return false;
            if(left_min < 0)
                left_min = 0;
        }
        return left_min == 0;
    }
};