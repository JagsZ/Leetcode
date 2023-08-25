class Solution {
public:
    int n;
    int dp[101][101];
    bool interleaving(int i, int j,string &s1, string &s2, string &s3){
        if(i+j>=n) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool takes1 = false;
        bool takes2 = false;
        if(s1[i]==s3[i+j] && i<s1.length()) {
            takes1 = interleaving(i+1,j,s1,s2,s3);
        }
        if(s2[j]==s3[i+j] && j<s2.length()){
            takes2 = interleaving(i,j+1,s1,s2,s3);
        }
        return dp[i][j] = takes1 or takes2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        n = s3.length();
        memset(dp,-1,sizeof(dp));
        return interleaving(0,0,s1,s2,s3);
    }
};