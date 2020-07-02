#include<bits/stdc++.h>
using namespace std;

#define mxn 1<<18
#define inf 1000000001
pair<int,int> a[mxn];

void upd( int x ){
    a[x] = min( a[x*2+1], a[x*2+2] );
    if( !x ) return;
    upd((x-1)/2);
}
int main(){
    int n, m, base=1;
    scanf("%d",&n);
    while( base<n ) base*=2;
    for( int i=0; i<base*2; i++ ) a[i]={inf,0};
    for( int i=base-1; i<base-1+n; i++ ){
        scanf("%d",&a[i].first);
        a[i].second = i-base+2;
        upd((i-1)/2);
    }
    scanf("%d",&m);
    while(m--){
        int k, i, v;
        scanf("%d",&k);
        if(k==2){
            printf("%d\n",a[0].second);
            continue;
        }
        scanf("%d%d",&i,&v);
        i += base-2;
        a[i].first = v;
        upd((i-1)/2);
    }
    return 0;
}#include<bits/stdc++.h>
using namespace std;

#define mxn 1<<18
#define inf 1000000001
pair<int,int> a[mxn];

void upd( int x ){
    a[x] = min( a[x*2+1], a[x*2+2] );
    if( !x ) return;
    upd((x-1)/2);
}
int main(){
    int n, m, base=1;
    scanf("%d",&n);
    while( base<n ) base*=2;
    for( int i=0; i<base*2; i++ ) a[i]={inf,0};
    for( int i=base-1; i<base-1+n; i++ ){
        scanf("%d",&a[i].first);
        a[i].second = i-base+2;
        upd((i-1)/2);
    }
    scanf("%d",&m);
    while(m--){
        int k, i, v;
        scanf("%d",&k);
        if(k==2){
            printf("%d\n",a[0].second);
            continue;
        }
        scanf("%d%d",&i,&v);
        i += base-2;
        a[i].first = v;
        upd((i-1)/2);
    }
    return 0;
}
