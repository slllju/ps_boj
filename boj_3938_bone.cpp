#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second
#define nn 368
#define inf 1000000007

struct edge{
    int v, cp, fl, d;
    edge* rev;
    edge( int t1, int t2, int t3 ):v(t1),cp(t2),fl(0),d(t3){}
    int r(){ return cp-fl; }
    void push(int f){ fl+=f; rev->fl-=f; }
};
vector<edge*> adj[nn];
void add( int u, int v, int c, int d ){
    edge* e1 = new edge(v,c,d);
    edge* e2 = new edge(u,0,-d);
    e1->rev=e2; e2->rev=e1;
    adj[u].push_back(e1); adj[v].push_back(e2);
}
int mcmf(int n){
    int res=0, dst=nn-1;
    for( int i=0; i<=dst; i++ ){
        for( auto* j : adj[i] ) delete j;
        adj[i].clear();
    }    
    for( int i=0; i<dst; i++ ) add(i,i+1,2,0);
    while( n-- ){
        int u, v, d;
        scanf("%d%d%d",&u,&v,&d);
        add(u,v+1,1,-d);
    }
    while(1){
        vector<bool> inq(nn);
        vector<int> prev(nn,-1), dist(nn,inf);
        vector<edge*> path(nn);
        queue<int> qu;
        qu.push(0);
        dist[0]=0;
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            inq[u]=0;
            for( auto* e : adj[u] ){
                int v=e->v, d=dist[u]+e->d;
                if( 0<e->r() && d<dist[v] ){
                    dist[v] = d; prev[v] = u; path[v] = e;
                    if( !inq[v] ){ inq[v]=1; qu.push(v); }
                }
            }
        }
        if(prev[dst]<0) break;
        res -= dist[dst];
        for( int v=dst; v>0; v=prev[v] ) path[v]->push(1);
    }
    return res;
}
int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(!n) break;
        printf("%d\n",mcmf(n));
    }
    return 0;
}
