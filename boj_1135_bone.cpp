#include<bits/stdc++.h>
using namespace std;

#define mxn 50
int rt[mxn];
vector<int> ch[mxn];

int dfs( int x ){
    vector<int> cn;
    for( auto y : ch[x] ) cn.push_back(dfs(y));
    if( cn.empty() ) return 0;
    sort(cn.begin(),cn.end());
    int ret=cn.back()+1;
    for( int i=cn.size()-2, cnt=1; i>=0; i--, cnt++ ){
        if( cn[i]+1 > ret-cnt ){
            ret += (cn[i]+1-ret+cnt);
        }
    }
    return ret;
}
int main(){
    int n; 
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){
        scanf("%d",&rt[i]);
        if(i) ch[rt[i]].push_back(i);
    }
    printf("%d",dfs(0));
    return 0;
}
