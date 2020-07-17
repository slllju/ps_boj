#include<bits/stdc++.h>
using namespace std;

#define mxn 200002
int sum[mxn], chd[mxn], root[mxn];

void preproc(int n){
    for( int i=1; i<=n; i++ ){
        int v=0;
        for( int j=i; j; j/=10 ) v += j%10;
        v = (i+v)%n; 
        if( !v ) v = n;
        root[i] = v;
        chd[v]++;
    }
}
void topolog(int n){
    queue<int> q;
    for( int i=1; i<=n; i++ ) if( chd[i]==0 ) q.push(i);
    while( !q.empty() ){
        int u = q.front(), v = root[u];
        q.pop();
        sum[v] = max( sum[v], sum[u]+1 );
        if( chd[v]==1 ) q.push(v);
        chd[v]--;
    }
}
int cycle(int n){
    int ret = 0;
    for( int i=1; i<=n; i++ ){
        if( chd[i]==0 ) continue;
        int cnt = 0, tmp = 0;
        for( int j=i; chd[j]>0; j=root[j] ){
            chd[j]=0;
            cnt++;
            tmp = max( tmp, sum[j] );
        }
        ret = max( ret, cnt+tmp );
    }
    return ret;
}
int main(){
    int n;
    scanf("%d",&n);
    preproc(n);
    topolog(n);
    printf("%d",cycle(n));
    return 0;
}
