#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

bool a[10];

pii cal( int x ){
    pii ret={0,0};
    for( int i=1, j=5; i<=5 && x; i++, j-- ){
        ret.first += i*(x%10); ret.second+=j*(x%10);
        x /= 10;
    }
    return ret;
}
int chk( int x ){
    int ret = 0;
    while(x){
        int y = x%10;
        if(y){
            if( !a[y] ) return 0;
            if( ret&(1<<y) ) return 0;
        }
        ret |= 1<<y;
        x/=10;
    }
    return ret;
}
bool dup( int x, int y ){
    for( int i=1; i<10; i++ ) if( x&(1<<i) && y&(1<<i) ) return 1;
    return 0;
}
int main(){
    int n, k, tot;
    scanf("%d",&n);
    for( int i=0, j; i<n; i++ ){
        scanf("%d",&j);
        tot |= 1<<j;
        a[j] = 1;
    }
    scanf("%d",&k);
    if( !k ){ printf("0"); return 0; }

    vector< pair<int,int> > v2[126];
    vector< tuple<int,int,int> > v1;
    
    for( int i=1; i<100000; i++ ){
        int st = chk(i);
        if( st==0 ) continue;
        pii v = cal(i);
        v1.push_back({i,v.first,st});
        v2[v.second].push_back({i,st});
    }

    int ans1, ans2;
    for( auto i : v1 ){
        int cnt = 0, now = get<1>(i), st=get<2>(i);
        vector<int> tmp;
        for( auto j : v2[now] ){
            if( dup(st,j.second) ) continue;
            cnt++;
            ans1 = get<0>(i);
            ans2 = j.first;
            tmp.push_back(ans2);                
        }
        if( k>cnt ){ k-=cnt; continue; }
        for( auto j : tmp ){
            ans2 = j;
            if( --k == 0 ) break;
        }
        break;
    }

    printf("%d",ans1);
    for( int i=0, j=ans2; i<5; i++, j/=10 ) if( !j ) printf("0");
    printf("%d",ans2);
    return 0;
}
