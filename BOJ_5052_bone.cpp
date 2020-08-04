#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    char x = '(';
    cin >> n;
    vector<string> a;
    for( int i=0; i<n; i++ ){
        string b;
        cin >> b;
        for( int j=int(b.size()); j<10; j++ ) b.push_back(x);   // 숫자보다 작은 문자('(')로 10자리를 맞춰준다
        a.push_back(b);
    }
    sort(a.begin(),a.end());                                    // 모든 10자리 전화번호를 오름차순 정렬한다
    for( int i=1; i<n; i++ ){
        int cnt=0, pos=10;
        for( int j=0; j<10; j++ ){
            if( a[i-1][j]==x ) pos=min(pos,j);                  // 앞 번호가 끝나는 위치
            if( a[i][j]!=a[i-1][j] ) break;   
            cnt++;                                              // i번째 번호가 앞 번호와 일치하는 횟수
        }
        if(cnt==pos){ printf("NO\n"); return; }                 // 앞 번호가 i번째 번호에 완전히 포함
    }
    printf("YES\n");
}
int main(){ int tc; cin>>tc; while(tc--) solve(); return 0; }
