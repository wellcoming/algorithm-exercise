#include <bits/stdc++.h>
#define int long long
#define ull unsigned ll
#define N 17
#define P
using namespace std;
int n,m,p;
int f[N][N];//前i行，第i+1行状压为S的总数

signed main(){
    scanf("%lld%lld%lld",&n,&m,&p);

    for (int i = 0; i < 1<<m; ++i) {

    }

    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < 1<<m; ++s) {//i有s的占用
            for (int d = 0; d < 1<<m; ++d) {//i的构成是d
                f[i]
            }
        }
    }

}
