class Solution {
    int solve(int indx1, int indx2, string &s1, string &s2, vector<vector<int>> &memo){
        if(indx1 < 0 || indx2 < 0){
            return 0;
        }
        if(memo[indx1][indx2] != -1){
            return memo[indx1][indx2];
        }
        if(s1[indx1] == s2[indx2]){
            cout<<s1[indx1] << " " <<s2[indx2]<<endl;
            return memo[indx1][indx2] = 1 + solve(indx1-1, indx2-1, s1,s2, memo);
        }
        return memo[indx1][indx2] = max(solve(indx1-1, indx2,s1,s2, memo), 
                                        solve(indx1, indx2-1, s1,s2, memo));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        vector<vector<int>> memo(n1, vector<int>(n2, -1));
        return solve(n1-1, n2-1,text1, text2, memo);
    }
};