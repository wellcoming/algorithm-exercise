#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 505
#define P
#define mx(p,v) p=max(p,v)
#define cl(p) for(int tmp=0;tmp<=x;tmp++)p[tmp]=INT_MIN
using namespace std;
int n,x,y;
int R[N],W[N];
int f[N][N*N];//前i个的子集中，sum r至少为j时，sum w的最大值

bool check(int p){
    return f[n][p]>=p;
}

signed main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        getchar();
        char c= getchar();
        int a,b;
        scanf("%d%d",&a,&b);
        if (c=='B') R[i]= b, W[i]=-a;
        else        R[i]=-a, W[i]= b;
        x+= max(0, R[i]);
        y+= max(0, W[i]);
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= x; ++j)
            f[i][j]=INT_MIN;
    f[0][0]=0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            mx(f[i][j],f[i-1][j]);
            if (j-R[i]>=0 and f[i-1][j-R[i]]>=0)
                mx(f[i][j], f[i-1][j-R[i]]+W[i]);
        }
    }
    int l=0,r=min(x,y);
    while (l<r){
        int mid=((l+r)>>1)+1;
        if (check(mid))
            l=mid;
        else
            r=mid-1;
    }
    printf("%d",l);
}
