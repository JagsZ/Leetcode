class Solution {
    private:
    bool isPalindrome(string s, int l, int r){
        while(l <= r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void solve(int index, string &s, vector<string> &str, vector<vector<string>> &list){
        
        if(index == s.length()){
            list.push_back(str);
            return;
        } 
        
        for(int i = index; i < s.length(); ++i){
            
            if(isPalindrome(s, index, i)){
                str.push_back(s.substr(index, i+1-index));
                solve(i+1, s, str, list);
                str.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> list;
        vector<string> str;
        solve(0, s, str, list);
        return list;
    }
};