class Solution {
    
public:
    bool detectCapitalUse(string word) {
        int n = word.length(), index = 0;
        
        if(word[index] <= 91){
            index++;
            if(index < n && word[index] <= 91){
                while(index < n){
                    if(word[index] >= 92)
                        return false;
                    index++;
                }
            }else{
                while(index < n){
                    if(word[index] < 92)
                        return false;
                    index++;
                }
            }
        }else{
            index++;
            while(index < n){
                if(word[index] < 92)
                    return false;
                index++;
            }
        }
        return true;
    }
};