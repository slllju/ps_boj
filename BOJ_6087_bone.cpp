#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
#define f first
#define s second

#define nn 101
int d[4][nn][nn];
char a[nn][nn];

int main(){
    int n, m, sr, sc, er, ec, di[4]={1,0,-1,0};
    cin >> m >> n;
    for( int i=0, k=0; i<n; i++ ){
        scanf("%s",a[i]);
        for( int j=0; j<m; j++ ){
            if( a[i][j]=='C' ){
                if(!k ){ sr=i; sc=j; k=1; }
                else{ er=i; ec=j; }
            }
            for( int l=0; l<4; l++ ) d[l][i][j]=nn*nn;
        }
    }
    priority_queue<pair<pii,pii>> pq;
    for(int i=0;i<4;i++){
        d[i][sr][sc]=0;
        pq.push({{0,i},{sr,sc}});
    }
    while( !pq.empty() ){
        pair<pii,pii> u = pq.top();
        pq.pop();
        if( d[u.f.s][u.s.f][u.s.s] < -u.f.f ) continue;
        for( int i=0; i<4; i++ ){
            int r = u.s.f, c = u.s.s, cnt = -u.f.f + 1;
            if( i==u.f.s ){ r += di[i]; c += di[3-i]; cnt--; }
            if( 0<=r && 0<=c && r<n && c<m && a[r][c]!='*' && cnt<d[i][r][c] ){
                d[i][r][c] = cnt;
                pq.push({{-cnt,i},{r,c}});
            }
        }
    }
    n *= nn;
    for( int i=0; i<4; i++ ) n = min( n, d[i][er][ec] );
    cout << n;
    return 0;
}
