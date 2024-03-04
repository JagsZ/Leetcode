class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size()-1, ans = 0, res = 0;
        
        if( r == 0 && power >= tokens[0])
            return 1;
        
        while(l <= r){
            if(power >= tokens[l]){
                power -= tokens[l];
                l++;
                res++;
                ans = max(ans, res);
            }else{
                if(res >= 1){
                    power += tokens[r];
                    res--;
                    r--;
                }else{
                    break;
                }
                    
            }
        }
        return ans;
    }
};