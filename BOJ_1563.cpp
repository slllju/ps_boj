#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define mxn 1001
const int mod=1000000;

int dp[mxn][2][3];

int main(){
    
    int n, ans=0;
    scanf("%d",&n);
    
    dp[0][0][0]=1; dp[0][1][0]=1; dp[0][0][1]=1;
    
    for( int i=0; i<n; i++ ){
        for( int j=0; j<2; j++ ){
            for( int k=0; k<3; k++ ){
                if( !dp[i][j][k] ) continue;
                if( i==n-1 ){ ans=(ans+dp[i][j][k])%mod; continue; }
                
                dp[i+1][j][0] = (dp[i+1][j][0]+dp[i][j][k])%mod;
                if( j==0 ) dp[i+1][j+1][0] = (dp[i+1][j+1][0]+dp[i][j][k])%mod;
                if( k<2 ) dp[i+1][j][k+1] = (dp[i+1][j][k+1]+dp[i][j][k])%mod;

            }
        }
    }

    printf("%d",ans);
    return 0;
}
