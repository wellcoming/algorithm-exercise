#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 10
#define P 998244353
using namespace std;
int n;
int A[N];
map<int,int> ans[N][N][N][N];//f[i][j][k][w][m]表示前i个数中，选j个数，最大值为a[k]，最小值为a[w]，异或和为m的集个数

signed main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    for(int i = 1; i <= n; i++) ans[i][1][i][i][A[i]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = j; k <= i; ++k) {
                for (int l = k; l <= i; ++l) {
                    for (auto &p: ans[i][j][k][l]) {
                        int m = p.first;
                        int v = p.second;
                        ans[i + 1][j][k][l][m] = (ans[i][j][k][l][m] + v) % P;
                        ans[i + 1][j][k][i + 1][m ^ A[i + 1]] = (ans[i][j][k][l][m] + v) % P;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= n; ++j) {
        for (int k = j; k <= n; ++k) {
            for (int l = k; l <= n; ++l) {
                for (auto &p: ans[n][j][k][l]) {
                    int m = p.first;
                    int v = p.second;
                    ans = (ans + (ll) j * A[k] % P * A[l] % P * m % P * v % P) % P;
                }
            }
        }
    }
    printf("%lld\n", ans);
}
