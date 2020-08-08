#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define f first
#define s second

int main(){

    int n, ans=0;
    pii now;           // 상어의 위치
    int len=2, cnt=0;  // 상어의 몸집 크기, 상어가 먹은 고기 수
    int di[4]={1,0,-1,0};

    scanf("%d",&n);
    vector<vi> a(n), visited(n);
    for( int i=0; i<n; i++ ){
        for( int j=0; j<n; j++ ){
            int k; scanf("%d",&k);
            if(k==9){ now={i,j}; k=0; }
            visited[i].push_back(-1);
            a[i].push_back(k);
        }
    }

    while(1){
        vector<pair<int,pii>> fish;
        queue<pair<int,pii>> qu;
        qu.push({0,now});
        visited[now.f][now.s] = ans;
        while( !qu.empty() ){
            pair<int,pii> x = qu.front();
            qu.pop();
            for( int i=0; i<4; i++ ){
                int r = x.s.f+di[i], c = x.s.s+di[3-i];
                if( 0<=r && r<n && 0<=c && c<n && visited[r][c]!=ans && a[r][c]<=len ){
                    visited[r][c] = ans;
                    qu.push({x.f+1,{r,c}});
                    if( a[r][c] && a[r][c]<len ) fish.push_back({x.f+1,{r,c}});
                }
            }
        }
        if( fish.empty() ) break;
        sort(fish.begin(),fish.end());
        ans += fish.front().f;
        now  = fish.front().s;
        a[now.f][now.s] = 0;
        if( ++cnt == len ){
            len++;
            cnt = 0;
        }
    }
    printf("%d",ans);
    return 0;   
}
