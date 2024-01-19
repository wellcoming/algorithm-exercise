#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define N 505
#define P
using namespace std;
int n;
vector<pair<int, int>> A, B, T;
int af[N*N],bf[N*N],tf[N*N];

int cac(vector<pair<int, int>> &v, int (&f)[N*N]) {
    int mx = accumulate(v.begin(), v.end(), 0, [](int a, pair<int, int> b) { return a+b.first; });
//    memset(f,0,sizeof f);
    for (auto i:v) {
        for (int j = mx; j >= i.first; --j) {
            f[j] = max(f[j],f[j-i.first]+i.second);
        }
    }
    for (int i = 1; i <= mx; ++i) f[i] = max(f[i], f[i - 1]);
    return mx;
}

signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        getchar();
        char c = getchar();
        int a, b;
        scanf("%d%d", &a, &b);
        if (c == 'A')A.emplace_back(a, b);
        else if (c == 'B')B.emplace_back(a, b);
        else T.emplace_back(a, b);
    }
    int ma=cac(A,af);
    int mb=cac(B,bf);
    int mt=cac(T,tf);
    int i=0,j=0,k=0,mxv=max(af[ma]+ma,max(bf[mb]+mb,tf[mt]+mt)),ans=0;
    for (int v = 0; v <= mxv; ++v) {
        while (i+1<=ma and af[i+1]+i+1<=v)i++;
        while (j+1<=mb and bf[j+1]+j+1<=v)j++;
        while (k+1<=mt and tf[k+1]+k+1<=v)k++;
        ans=max(ans,af[i]+bf[j]+tf[k]-v);
    }

    printf("%d", ans);
}
