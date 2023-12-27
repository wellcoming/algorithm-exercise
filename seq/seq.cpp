#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 200005
#define SN 448
#define P 1000000007
using namespace std;
int n,l,sn;
int A[N];
int ans[N];
int f[N*2][SN+5];//i开始，间隔为j

signed main(){
    scanf("%d%d",&n,&l);
    sn=ceil(sqrt(n));
    for (int i = 1; i <= n-1; ++i) {
        scanf("%d",&A[i]);
    }
    
    ans[n]=1;
    fill(&f[n][1],&f[n][sn+1],1);
    
    for (int i = n-1; i >= 1; --i) {
        if (A[i] > sn){
            for (int k = 1; k <= min(l, (n-i) / A[i]); ++k) {
                ans[i]= (ans[i] + ans[i + k * A[i]]) % P;
            }
        } else {
            int d = A[i];
            ans[i]=f[i+d][d];
            if (i+d*(l+1)<=n)
                ans[i]=(ans[i]+P-f[i+d*(l+1)][d])%P;
        }
        for (int j = 1; j <= sn; ++j) {
            f[i][j]= (f[i+j][j]+ans[i])%P;
        }

    }
    for (int i = 1; i <= n-1; ++i) {
        printf("%d ", ans[i]);
    }
}
