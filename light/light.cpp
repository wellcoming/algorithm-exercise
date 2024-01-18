#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 1005
#define P 10007
#define C(a,b) (c[a][b])
using namespace std;
int n,m,o;
int f[N][N];//第i次操作，场上有j个1的方案数
bool cc[N];
int c[N][4];

void init(){
    memset(f,0,sizeof f);
    o=0;
    getchar();
    for (int i = 1; i <= n; ++i)
        cc[i]= getchar() == '1';
    getchar();
    for (int i = 1; i <= n; ++i)
        if (cc[i] ^ (getchar() == '1'))o++;
}
int extgcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int d= extgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int inv(int a){
    int x,y;
    extgcd(a,P,x,y);
    return (x%P+P)%P;
}

void solve(){
    int fac=1;
    f[0][o]=1;
    for (int i = 1; i <= m; ++i) {
        fac=fac*i%P;
        for (int j = 0; j <= n; ++j) {
            if (j-3>=0)f[i][j]=(f[i][j]+f[i-1][j-3]*C(j-3,0)*C(n-(j-3),3))%P;
            if (j-1>=0)f[i][j]=(f[i][j]+f[i-1][j-1]*C(j-1,1)*C(n-(j-1),2))%P;
            if (j+1<=n)f[i][j]=(f[i][j]+f[i-1][j+1]*C(j+1,2)*C(n-(j+1),1))%P;
            if (j+3<=n)f[i][j]=(f[i][j]+f[i-1][j+3]*C(j+3,3)*C(n-(j+3),0))%P;
            if (i>1)   f[i][j]=(f[i][j]-(i-1)*f[i-2][j]*(C(n,3)-i+2))%P;
        }
    }
    printf("%d\n",f[m][0]*inv(fac)%P);
}

signed main(){
    c[0][0]=1;
    for (int i = 1; i < N; ++i) {
        c[i][0]=1;
        for (int j = 1; j <= 3; ++j) {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
        }
    }
    while (scanf("%d%d",&n,&m) and n){
        init();
        solve();
    }


}
