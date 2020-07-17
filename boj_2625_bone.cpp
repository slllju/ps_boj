#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
#define f first
#define s second

#define mxl 1001
#define mxk 31
char a[mxl], b[mxl];
int dp[mxl][mxl], hi[mxl];

int id( char x ){
    if(x=='A') return 0;
    if(x=='C') return 1;
    if(x=='G') return 2;
    return 3;
}
char di( int x ){
    if(x==0) return 'A';
    if(x==1) return 'C';
    if(x==2) return 'G';
    return 'T';
}
int main(){

    int la,lb,k;
    scanf("%d",&k);
    scanf("%d",&la); scanf("%s",a);
    scanf("%d",&lb); scanf("%s",b);

    // 1. 최대 길이 DP
    int len = 0;
    for( int i=la-1; i>=0; i-- ){
        for( int j=lb-1; j>=0; j-- ){
            hi[j] = 0;
            int val = 0, col = 0;
            for( int x=1; x<=k+1; x++ ){
                if( i+x<la ) col = max( col, dp[i+x][j] );
                if( j+x<lb ) val = max( val, hi[j+x] );
            }
            if( a[i]==b[j] ){
                dp[i][j] = val+1;
                len = max( len, dp[i][j] );
            }
        }
    }

    // 2. BFS 준비
    queue<pii> pos[4], now;
    for( int i=0; i<la; i++ ){
        for( int j=0; j<lb; j++ ){
            if( dp[i][j]==len ){
                pos[id(a[i])].push({i,j});
                dp[i][j]=0;
            }
        }
    }

    // 3. 사전식 문자 선택
    string ans;
    while( len-- ){
        for( int i = 0, x = -1; i < 4; i++ ){
            if( x<0 && !pos[i].empty() ){
                x=i;
                ans.push_back(di(x));
            }
            while( !pos[i].empty() ){
                if(i==x) now.push(pos[i].front());
                pos[i].pop();
            }
        }
        while( !now.empty() ){
            pii x = now.front();
            now.pop();
            for( int i=x.f+1; i<=min(la-1,x.f+k+1); i++ ){
                for( int j=x.s+1; j<=min(lb-1,x.s+k+1); j++ ){
                    if( dp[i][j]==len ){
                        dp[i][j]=0;
                        pos[id(a[i])].push({i,j});
                    }
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}
