#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mxn 500001
bool chk[mxn], cit[mxn];
int cnt[mxn], grp[mxn];
vector<int> adj[mxn];

void dfs( int x, int w ){
    if( grp[x] ) return;
    grp[x] = w;
    for( auto y : adj[x] ) dfs( y, w );
}
int main(){
    int n, u, ans=0;
    
    // 입력 및 그래프 처리
    cin >> n ;
    for( int i=1; i<=n; i++ ){
        scanf("%d",&u);
        for( auto j : adj[i] ) if( j==u ) u=0;
        if( !u ) continue;
        cnt[u]++; cnt[i]++;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    // DFS로 grouping
    int gcnt=0;
    for( int i=1; i<=n; i++ ) if( !grp[i] ) dfs( i, ++gcnt );
    vector<int> grplist[gcnt+1];
    for( int i=1; i<=n; i++ ) grplist[grp[i]].push_back(i);
    
    // 시작 조건에 맞는 노드 큐에 삽입
    queue<int> qu;
    for( int i=1; i<=n; i++ ){
        if( cnt[i]<=1 ){
            qu.push(i);
            chk[ i ] = 1;
        }
    }

    // 단순 경로 사이클 처리
    for( int i=1; i<=gcnt; i++ ){
        bool f = 1;
        for( auto j : grplist[i] ) if( cnt[j]!=2 ) f = 0;
        if( f ){
            qu.push(grplist[i][0]);
            chk[ grplist[i][0] ] = 1;
        }
    }

    // 마피아가 될 수 있는 노드를 최대로 찾기
    while( !qu.empty() ){
        u = qu.front();
        qu.pop();
        if( cit[u] ) continue;
        ans++;
        for( auto i : adj[u] ){
            if( cit[i] ) continue;
            cit[i] = 1;
            for( auto j : adj[i] ){
                if( cit[j] || chk[j] ) continue;
                cnt[j]--;
                if( cnt[j]<=1 ){
                    chk[j] = 1;
                    qu.push(j);
                }
            }
        }
    }

    cout << ans;
    return 0;
}
