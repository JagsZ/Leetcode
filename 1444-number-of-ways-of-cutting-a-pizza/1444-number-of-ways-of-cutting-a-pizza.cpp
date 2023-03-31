class Solution {
     int m,n;
    int mod=1e9+7;
    int ***dp;

//use precomputation forhasApple()
    bool hasApple(vector<string>& pizza, int srow, int erow, int scol, int ecol){
        for(int i=srow; i<erow; i++) {
            for(int j=scol; j<ecol; j++) {
                if(pizza[i][j]=='A')
                    return true;
            }
        }
        return false;
    }
    /*
    int solve(int row, int col, int m, int n, vector<string> &pizza, int k){
        
        if(row == m || col == n)
            return 0;
        
        if(k == 1){
            if(hasAnApple(row, col, m, n, pizza)){
                return 1;
            }
            return 0;
        }
        
        int ans = 0;
        for(int i = row+1; i < m; i++){
            if(hasAnApple(row, col, i, n, pizza)){
                ans += solve(i, col, m, n, pizza, k-1);
                ans %= mod;
            }
        }
        
        for(int j = col+1; j < n; j++){
            if(hasAnApple(col, row, j, m, pizza)){
                ans += solve(row, j, m, n, pizza, k-1);
                ans %= mod;
            }
        }
        return ans;
    }*/
public:
    int ways(vector<string>& pizza, int K) {
        m=pizza.size();
        n=pizza[0].size();
        dp=new int**[m+1];
        for(int i=0;i<=m;i++) {
            dp[i]=new int*[n+1];
            for(int j=0;j<=n;j++) {
                dp[i][j]=new int[K+1];
            }
        }

        // return fun(0,0,pizza,K);

        for(int srow=m; srow>=0; srow--) {
            for(int scol=n; scol>=0; scol--){
                for(int k=1;k<=K;k++) {
                    if(srow==m || scol==n){
                        dp[srow][scol][k]=0;
                        continue;
                    }

                    if(k==1){
                        if(hasApple(pizza,srow,m,scol,n)) dp[srow][scol][k]=1;
                        else dp[srow][scol][k]=0;
                    }
                    else
                    {
                        int ans=0;

                        //cut horizontally
                        for(int nextrow=srow+1; nextrow<m; nextrow++) {
                            if(hasApple(pizza, srow, nextrow, scol, n)) {
                                ans+=dp[nextrow][scol][k-1];
                                ans%=mod;
                            }
                        }

                        //cut vertically
                        for(int nextcol=scol+1; nextcol<n; nextcol++) {
                            if(hasApple(pizza, srow, m, scol, nextcol)) {
                                ans+=dp[srow][nextcol][k-1];
                                ans%=mod;
                            }
                        }

                        dp[srow][scol][k]=ans;
                    }
                }
            }
        }

        return dp[0][0][K];
    }
};