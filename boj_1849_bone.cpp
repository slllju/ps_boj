#include<bits/stdc++.h>
using namespace std;

#define mxn 1<<18
#define len 100000
int cnt[mxn], a[len];

int find( int x, int s, int e, int sum ){
    if(s==e) return s;
    if( cnt[x*2+1]<sum ) return find(x*2+2,(s+e)/2+1,e,sum-cnt[x*2+1]);
    return find(x*2+1,s,(s+e)/2,sum);
}
void upd( int x, int d ){
    cnt[x] += d;
    if(x) upd((x-1)/2,d);
}
int main(){
    int n, base=1;
    scanf("%d",&n);
    while( base < n ) base*=2;
    for( int i=base-1; i<base-1+n; i++ ) upd(i,1);
    for( int i=0, j; i<n; i++ ){
        scanf("%d",&j);
        j = find(0,1,base,j+1)-1;
        a[j] = i+1;
        upd(base+j-1,-1);        
    }
    for( int i=0; i<n; i++ ) printf("%d\n",a[i]);
    return 0;
}
