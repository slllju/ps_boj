#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define f first
#define s second

#define mxn 102
#define mxk 26

char a[mxn][mxn];
bool vi[mxn][mxn], k1[mxk];

int wk( char x ){
    if( 'a'<=x && x<='z' ) return 1;
    if( 'A'<=x && x<='Z' ) return 2;
    return 0;
}
int main(){
    int tc, di[4]={1,0,-1,0};
    scanf("%d",&tc);
    while(tc--){

        string ks;
        queue<pii> qu, door[26];
        int n, m, ans=0;
        
        scanf("%d%d",&n,&m);
        for( int i=1; i<=n; i++ ){
            scanf("%s",a[i]);
            for( int j=1; j<=m; j++ ) vi[i][j]=0;
        }
        cin >> ks;
        for( int i=0; i<mxk; i++ ) k1[i]=0;
        for( auto i : ks ) k1[i-'a']=1;
        for( int i=0; i<=n+1; i++ ){
            for( int j=0; j<=m+1; j++ ){
                if(i&&i<=n&&j&&j<=m) continue;
                vi[i][j]=1;
                qu.push({i,j});
            }
        }

        while( !qu.empty() ){
            pii u = qu.front();
            qu.pop();
            for( int i=0; i<4; i++ ){
                int r = u.f + di[i], c = u.s + di[3-i];
                if( r<1 || r>n || c<1 || c>m || vi[r][c] || a[r][c-1]=='*' ) continue;
                int w = wk(a[r][c-1]);
                if( a[r][c-1]=='$' ) ans++;
                if( w==1 ){
                    int x = a[r][c-1]-'a';
                    if( !k1[x] ){
                        k1[x]=1;
                        while( !door[x].empty() ){
                            qu.push(door[x].front());
                            door[x].pop();
                        }
                    }
                }
                if( w==2 ){
                    int x = a[r][c-1]-'A';
                    if( !k1[x] ){
                        door[x].push({r,c});
                        vi[r][c]=1;
                        continue;
                    }
                }
                vi[r][c]=1;
                qu.push({r,c});
            }
        }
        printf("%d\n",ans);        
    }
    return 0;
}
