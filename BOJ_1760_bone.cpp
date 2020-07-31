#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define nn 100
int a[nn][nn];  // grid
int gc[nn][nn]; // group of col

bool dfs( int u, vector<vi> &adj, vi &did, vi &wit, int dc ){
    if( did[u] == dc ) return 0;
    did[u] = dc;
    for( auto v : adj[u] ){
        if( !wit[v] || dfs(wit[v],adj,did,wit,dc) ){
            wit[v] = u;
            return 1;
        }
    }
    return 0;
}
int main(){
    int n, m, n2=0, m2=0;
    
    // 입력
    cin >> n >> m;
    for( int i=0; i<n; i++ ) for( int j=0; j<m; j++ ) scanf("%d",&a[i][j]);
    
    // m개의 column을 m2개로 그룹핑
    for( int j=0; j<m; j++ ){
        for( int i=0; i<n; i++ ){
            if( a[i][j] ) continue;
            m2++;
            int i2=i;
            while( i2<n && a[i2][j]!=2 ) gc[i2++][j] = m2;
            i = i2-1;
        }
    }

    // n개의 row를 n2개로 그룹핑, 동시에 간선 형성
    vector<vi> adj;
    adj.push_back(vi());
    for( int i=0; i<n; i++ ){
        for( int j=0; j<m; j++ ){
            if( a[i][j] ) continue;
            n2++;
            vi tmp;
            while( j<m && a[i][j]!=2 ){
                if( a[i][j]==0 && gc[i][j]>0 ) tmp.push_back(gc[i][j]);
                j++;
            }
            adj.push_back(tmp);
        }
    }

    // 이분 매칭
    int ans = 0;    // 최대 매칭 횟수
    vi did(n2+1);   // 방문 체크
    vi wit(m2+1);   // 열 그룹이 연결된 행 그룹 넘버 저장
    for( int i=1; i<=n2; i++ ) ans += dfs(i,adj,did,wit,i);

    // 출력
    cout << ans;
    
    return 0;
}
