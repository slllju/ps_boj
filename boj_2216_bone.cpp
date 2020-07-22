#include<bits/stdc++.h>
using namespace std;

#define nn 3002
#define inf 1000000007

int dp[nn][nn];
       
int main(){
    string a, b;
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3 >> a >> b;
    
    int n = a.size(), m = b.size();
    for( int i=0; i<=n; i++ ) for( int j=0; j<=m; j++ ) dp[i][j]=-inf;
    dp[0][0]=0;
    for( int i=0; i<=n; i++ ){
        for( int j=0; j<=m; j++ ){
            if( !i && !j ) continue;
            if( !i ){ dp[i][j]=dp[i][j-1]+s2; continue; }
            if( !j ){ dp[i][j]=dp[i-1][j]+s2; continue; }
            if( a[i-1]==b[j-1] ) dp[i][j]=dp[i-1][j-1]+s1;
            else dp[i][j]=dp[i-1][j-1]+s3;
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1])+s2);
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}
