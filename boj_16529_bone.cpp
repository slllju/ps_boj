#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define f first
#define s second

#define mxn 100001
vector<int> chd[mxn];

pii dfs( int u )
{
    pii res={0,0};
    int cnt[3]={0,0,0};
    for( auto v : chd[u] ){
        pii tmp = dfs( v );
        res.s += tmp.s;
        cnt[tmp.f]++;
    }
    while( cnt[2]>0 ){ cnt[2]--; res.s++; }
    if( cnt[0]+cnt[1]+cnt[2]>1 ) res.f = 1;
    if( cnt[0]+cnt[1]+cnt[2]>2 && cnt[1]+cnt[2]>0 ) res.f = 2;
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for( int v=2; v<=n; v++ ){
        int u;
        scanf("%d",&u);
        chd[u].push_back(v);
    }
    printf("%d",dfs(1).s);
    return 0;
}
