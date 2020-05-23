// https://www.acmicpc.net/problem/12874
// I solved this problem on May 24, 2020.

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define mxo 50
#define mxn 101
#define mod 1000000007

char a[mxn];
int dp[mxn][mxo+1], ans;

int main(){
    scanf("%s",a);
    dp[0][0] = 1;
    for( int i=0, lim=0, n = strlen(a); i<=n; i++ ){

        bool op = 0;                    // close
        if( i && a[i-1]=='(' ) op = 1;  // open
        int ro=i, rc=i;                 // right open & close
        for( int j=i+1; j<=n && (ro==i||rc==i); j++ ){
            if( ro==i && a[j-1]=='(' ) ro=j;
            if( rc==i && a[j-1]==')' ) rc=j;
        }

        for( int j=0; j<=lim; j++ ){
            if( i<ro && j<mxo ) dp[ro][j+1] = (dp[ro][j+1]+dp[i][j])%mod;
            if( i<rc && j ) dp[rc][j-1] = (dp[rc][j-1]+dp[i][j])%mod;
        }

        if(i) ans = (ans+dp[i][0])%mod;
        if( i<ro ) lim = min(mxo,lim+1);
    }
    printf("%d",ans);
    return 0;
}
