#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 10
#define P 998244353
using namespace std;
int n;
int a[N];
map<int,int> f[N][N][N][N];//f[i][j][k][l][m]表示前i个数中，选j个数，最大值为a[k]，最小值为a[l]，异或和为m的集个数

signed main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) f[i][1][i][i][a[i]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = j; k <= i; ++k) {
                for (int l = k; l <= i; ++l) {
                    for (auto &p: f[i][j][k][l]) {
                        int m = p.first;
                        int v = p.second;
                        f[i + 1][j][k][l][m] = (f[i][j][k][l][m] + v) % P;
                        f[i + 1][j][k][i+1][m ^ a[i + 1]] = (f[i][j][k][l][m] + v) % P;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= n; ++j) {
        for (int k = j; k <= n; ++k) {
            for (int l = k; l <= n; ++l) {
                for (auto &p: f[n][j][k][l]) {
                    int m = p.first;
                    int v = p.second;
                    ans = (ans + (ll) j*a[k]%P*a[l]%P*m%P*v%P)%P;
                }
            }
        }
    }
    printf("%lld\n", ans);
}
