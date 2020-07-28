#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
#define f first
#define s second

#define nn 100001
vi adj[nn], prm;
int pn[nn], ans[nn];

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
int main(){
    vector<pair<int,pii>> qr;
    int n, m=0;

    // 1. 입력
    scanf("%d",&n);
    for( int i=1; i<=n; i++ ){
        int u, v;
        scanf("%d%d",&u,&v);
        qr.push_back({v,{u,i}});
    }

    // 2. 소수 처리
    for( int i=2; i<nn; i++ ){
        if(ans[i]){
            adj[ans[i]].push_back(i);
            continue;
        }
        adj[i].push_back(i);
        prm.push_back(i);
        for( int j=i; j<nn; j+=i ) ans[j]=i;
    }

    // 3. 쿼리를 정렬하여 처리
    sort(qr.begin(),qr.end());
    vi pt(nn+1,0);    // 펜윅 트리
    int pi = 0;       // 소수(p)를 어디까지 사용했는지 인덱스(i)
    int len = prm.size();
    for( auto i : qr ){
        while( prm[pi]<=i.f && pi<len ){
            for( auto k : adj[prm[pi]] ) upt( pt, k, 1 );
            pi++;
        }
        ans[i.s.s] = sum( pt, i.s.f );
    }
    for( int i=1; i<=n; i++ ) printf("%d\n",ans[i]);
    return 0;
}
