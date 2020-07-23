#include<bits/stdc++.h>
using namespace std;

#define nn 2000
#define inf 1000000007
int dp[nn][21], sum[nn];

int cal( int x ){
    x+=5;
    x-=x%10;
    return x;
}
int main(){
    int n, k, ans=inf;
    scanf("%d%d",&n,&k);
    for( int i=0; i<n; i++ ){
        int x;
        scanf("%d",&x);
        sum[i] = x;
        if( i ) sum[i] += sum[i-1];
        for( int j=0; j<=k; j++ ){
            dp[i][j]=inf;
            if(!j) dp[i][j]=cal(sum[i]);
            else for( int t=0; t<i; t++ ){
                dp[i][j]=min(dp[i][j],dp[t][j-1]+cal(sum[i]-sum[t]));
            }
            if(i==n-1) ans=min(ans,dp[i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}
