#include<bits/stdc++.h>
using namespace std;

#define mxn 2000
bool dp[mxn][mxn];
int a[mxn];

int main(){
    int n;
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){
        scanf("%d",&a[i]);
        dp[i][i]=1;
    }
    for( int i=2; i<=n; i++ ){
        for( int s=0; s<n; s++ ){
            int e = s+i-1;
            if( e>=n ) break;
            if( a[s]!=a[e] ) continue;
            if( i==2 || dp[s+1][e-1] ) dp[s][e] = 1;
        }
    }
    scanf("%d",&n);
    while( n-- ){
        int s, e;
        scanf("%d%d",&s,&e);
        printf("%d\n",dp[s-1][e-1]);
    }
    return 0;
}
