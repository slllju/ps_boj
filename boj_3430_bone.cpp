#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define f first
#define s second

#define mxn 1000002
vector<int> pos[mxn];
int a[mxn];
bool did[mxn];

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n, m;
        scanf("%d%d",&n,&m);
        for( int i=1; i<=n; i++ ){
            pos[i].clear();
            pos[i].push_back(0);
            did[i]=0;
        }
        int cnt=0;
        for( int i=1; i<=m; i++ ){
            scanf("%d",&a[i]);
            if(a[i]>0) pos[a[i]].push_back(i);
            else cnt++;
        }
        if( cnt < m-cnt ){ printf("NO\n"); continue; }
        vector<int> ans;
        bool win=1;
        priority_queue<pii> pq;
        for( int i=m; i>=1; i-- ){
            int x = a[i];
            if( x>0 ){
                if( did[x] ){ win=0; break; }
                pos[x].pop_back();
                pq.push({pos[x].back(),x});
                did[x] = 1;
                continue;
            }
            if( pq.empty() ) ans.push_back(0);
            else{   
                int j = pq.top().s;
                pq.pop();
                did[j] = 0;
                ans.push_back(j);
            }
        }
        if( !pq.empty() ) win = 0;
        if( !win ) printf("NO\n");
        else{ printf("YES\n"); for( int i=cnt-1; i>=0; i-- ) printf("%d ",ans[i]); printf("\n"); }
    }
    return 0;    
}
