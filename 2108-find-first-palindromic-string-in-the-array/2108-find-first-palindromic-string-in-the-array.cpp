class Solution {
    bool palindrome(string str){
        bool status = true;
        int l=0,r=str.length()-1;
        while(l<r){
            if(str[l]!=str[r]){
                status = false;
                break;
            }
            l++;
            r--;
        }
        return status;
    }
    
public:
    string firstPalindrome(vector<string>& words) {
        string str;
        for(int i=0;i<words.size();i++){
            str = words[i];
            if(palindrome(str))
                return str;
        }
        return "";
    }
};