#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define nn 1026
#define hh 11

char a[nn][nn];
pii path[nn][hh];
vector<int> adj[nn];
int cnt[nn];

void proc(int n){
    set<int> has;
    for( int i=1; i<=n; i++ ){
        scanf("%s",a[i]);
        for( int j=n; j; j-- ) a[i][j]=a[i][j-1];
        has.insert(i);
    }
    int lev=0;
    while(n>1){
        vector<int> win, now;
        set<int> tmp, used;
        // 1번을 이기는 사람 추출 : win
        for( auto i : has ){
            adj[i].clear();
            cnt[i] = 0;
            if( a[i][1]=='1' ) win.push_back(i);
        }
        // win을 이길 수 있는 사람 추출 : tmp
        queue<int> tq;
        for( auto i : has ){
            for( auto j : win ){
                if( a[i][j]=='1' ){
                    adj[i].push_back(j);
                    cnt[j]++;
                    if( !tmp.count(i) ) tmp.insert(i);
                }
            }
        }
        // tmp와 win을 대상으로 위상정렬 하면서 쌍을 찾고 used에 추가하기
        // 이긴 사람을 now에 추가
        for( auto i : tmp ) if( cnt[i]==0 ) tq.push(i);
        while( !tq.empty() ){
            int u = tq.front();
            tq.pop();
            for( auto v : adj[u] ){
                if( !cnt[v] ) continue;
                cnt[v]--;
                if( cnt[v]==0 ){
                    tq.push(v);
                    if( !used.count(u) ){
                        used.insert(u);
                        used.insert(v);
                        path[u][lev] = {u,v};
                        now.push_back(u);
                    }
                }
            }
        }
        for( auto i : used ) has.erase(i);
        for( auto i : has ){
            if( a[1][i]=='1' ){
                has.erase(1);
                has.erase(i);
                path[1][lev]={1,i};
                now.push_back(1);
                break;
            }
        }
        win.clear();
        for( auto i : has ) win.push_back(i);
        has.clear();
        for( int i=0; i<win.size(); i+=2 ){
            int u = win[i], v = win[i+1];
            if( a[v][u]=='1' ) swap(u,v);
            now.push_back(u);
            path[u][lev]={u,v};
        }
        for( auto i : now ) has.insert(i);
        n/=2;
        if(n>1) lev++;
    }
    queue<pii> qu;
    vector<pii> ans;
    qu.push({1,lev});
    while( !qu.empty() ){
        int u = qu.front().f, l = qu.front().s;
        qu.pop();
        ans.push_back(path[u][l]);
        if(l>0){
            qu.push({path[u][l].f,l-1});
            qu.push({path[u][l].s,l-1});
        }
    }
    for( int i=ans.size()-1; i>=0; i-- ) printf("%d %d\n",ans[i].f,ans[i].s);
}
int main(){ int n; while(~scanf("%d",&n) ) proc(n); return 0; }
