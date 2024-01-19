#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;

const int N = 503;

vint f(1), g(1), h(1);

int main() {
    int n; cin >> n;
    assert(1 <= n && n <= 500);
    auto add = [&](vint &f, int a, int b) {
        int n = f.size() + a;
        f.resize(n);
        for (int i = n - 1; i >= a; --i) f[i] = max(f[i], f[i - a] + b);
    };
    while (n--) {
        char c; int a, b;
        cin >> c >> a >> b;
        assert(c == 'A' || c == 'T' || c == 'B');
        assert(1 <= a && a <= 500 && 1 <= b && b <= 500);
        if (c == 'A') add(f, a, b);
        else if (c == 'T') add(g, a, b);
        else add(h, a, b);
    }
    for (int i = 1; i < f.size(); ++i) f[i] = max(f[i], f[i - 1]);
    for (int i = 1; i < g.size(); ++i) g[i] = max(g[i], g[i - 1]);
    for (int i = 1; i < h.size(); ++i) h[i] = max(h[i], h[i - 1]);
    int i = 0, j = 0, k = 0, ans = 0;
    int xn = max({f.back() + f.size(), g.back() + g.size(), h.back() + h.size()});
    for (int v = 0; v <= xn; ++v) {
        while (i + 1 < f.size() && f[i + 1] + i + 1 <= v) ++i;
        while (j + 1 < g.size() && g[j + 1] + j + 1 <= v) ++j;
        while (k + 1 < h.size() && h[k + 1] + k + 1 <= v) ++k;
        ans = max(ans, f[i] + g[j] + h[k] - v);
    }
    cout << ans << '\n';

    return 0;
}
 