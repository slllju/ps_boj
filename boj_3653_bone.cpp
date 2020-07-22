#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
#define f first
#define s second

int sum( vi &pt, int i ){
    int res = 0;
    while( i>0 ){
        res += pt[i];
        i -= (i&-i);
    }
    return res;
}
void upt( vi &pt, int i, int x ){
    while( i < pt.size() ){
        pt[i] += x;
        i += (i&-i);
    }
}
void proc(){
    int n, m;
    scanf("%d%d",&n,&m);
    vi pt(n+m+1), pos(n+1);
    for( int i=1; i<=n; i++ ){
        pos[n-i+1] = i;
        upt( pt, i, 1 );
    }
    for( int i=1; i<=m; i++ ){
        int x;
        scanf("%d",&x);
        printf("%d ",n-sum( pt, pos[x] ));
        upt( pt, pos[x], -1 );
        pos[x] = n+i;
        upt( pt, n+i, 1 );
    }
    printf("\n");
}
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--) proc();
    return 0;
}
