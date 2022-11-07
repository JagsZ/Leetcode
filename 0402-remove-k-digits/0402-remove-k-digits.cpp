class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans = "";
        int count = 0;
        for(int i = 0; i < num.length(); i++){
            while(ans.size() && k > 0 && ans.back() > num[i]){
                ans.pop_back();
                k--;
            }
            if(ans.size() || num[i] != '0')
                ans.push_back(num[i]);
        }
        while(ans.size() && k){
            ans.pop_back();
            k--;
        }
        return (ans == "")? "0": ans;
    }
};