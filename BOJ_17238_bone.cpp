// https://www.acmicpc.net/problem/17238 ... I solved this problem on June 7, 2020

#include<bits/stdc++.h>
using namespace std;

#define mxn 102
int val[mxn][mxn];
vector<int> ed[mxn];
int visited[mxn], conn[mxn];

bool dfs( int x ){              // 이분 매칭
    if( visited[x] ) return 0;
    visited[x] = 1;
    for( auto y : ed[x] ){
        if( !conn[y] || dfs(conn[y]) ){
            conn[y] = x;
            return 1;
        }
    }
    return 0;
}
int main(){
    int n, i, j, k, low=0, mid, high=0, ans;
    scanf("%d",&n);
    for( i=1; i<=n; i++ ) scanf("%d",&val[i][0]);
    for( i=1; i<=n; i++ ){
        scanf("%d",&k);
        for( j=1; j<=n; j++ ){
            val[j][i] = val[j][0]^k;
            high = max( high, val[j][i] );
        }
    }
    while( low<=high ){         // 최저퀄리티의 최고값에 대한 이분탐색
        mid = (low+high)/2;
        for( i=1; i<=n; i++ ){
            ed[i].clear();
            conn[i] = 0;
            for( j=1; j<=n; j++ ) if( val[i][j]>=mid ) ed[i].push_back(j);  // 이분 그래프 간선
        }
        k=0;
        for( i=1; i<=n; i++ ){
            k += dfs(i);
            for( j=1; j<=n; j++ ) visited[j] = 0;
        }
        if( k==n ) ans = mid, low = mid+1;    // 모두 매칭
        else high = mid-1;
    }
    printf("%d",ans);
    return 0;
}
