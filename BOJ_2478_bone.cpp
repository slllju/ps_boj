#include<cstdio>
using namespace std;

#define mxn 502
int a[mxn], b[mxn], n;

bool rev( int x ){  // x번째 자물쇠가 뒤집혀 있으면 1을 반환
    a[0] = a[n];
    a[n+1] = a[1];
    if( (a[x]==1&&a[x-1]==n) || a[x]==a[x-1]+1 ) return 0;
    if( (a[x]==n&&a[x+1]==1) || a[x]+1==a[x+1] ) return 0;
    return 1;
}

int main(){
    scanf("%d",&n);
    for( int i=1; i<=n; i++ ) scanf("%d",&a[i]);
    int l1=n, l2=n, p[2]={0,0}, q[2]={0,0};

    // 뒤집힌 구간이 두 개라면 두 번째 왼쪽 밀기로 인해 분리되었다
    // 뒤집힌 구간이 자물쇠 중간에 한 번만 있으면 두 번째 왼쪽 밀기 무의미
    for( int i=1; i<=n; i++ ){
        if( rev(i) ){
            int t = 0;
            if( p[t] ) t++;     // 이미 뒤집힌 구간이 있으면 
            p[t] = q[t] = i;
            while( q[t]<n && rev(q[t]+1) ) q[t]++;
            i = q[t];
        }
    }
    if( p[1] ){     // 뒤집한 구간이 두 개면 왼쪽 밀기 횟수 구해줘야
        l2 = n - p[1] + 1;
        for( int i=p[1]; i<=n; i++ ) b[i-p[1]+1] = a[i];
        for( int i=p[1]-1; i; i-- ) a[i+l2] = a[i];
        for( int i=1; i<=l2; i++ ) a[i] = b[i];
        q[0] += l2; // 이런 경우에는 뒤집힌 구간을 항상 [1,q[0]]으로
    }
    // 뒤집힌 구간 원상복귀
    for( int i=p[0]; i<=q[0]; i++ ) b[q[0]+p[0]-i] = a[i];
    for( int i=p[0]; i<=q[0]; i++ ) a[i] = b[i];
    
    // 첫 번째 왼쪽 밀기는 n이 어디에 위치해 있는지로 판별
    for( int i=1; i<n; i++ ) if( a[i]==n ) l1 = n-i;
    
    printf("%d\n%d %d\n%d",l1,p[0],q[0],l2);
    return 0;
}
