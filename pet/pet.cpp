#include <bits/stdc++.h>
#define N 100005
#define int unsigned
#define ls(p) ((p) << 1)
#define rs(p) (((p) << 1) | 1)
#define fa(p) ((p) >> 1)

int n, q;
int P[N];
int xo[N];
int t[N << 2];
void pushup(int p) {
    t[p] = t[ls(p)] ^ t[rs(p)];
}
void build(int p = 1, int l = 1, int r = n) {
    if (l >= r) {
        t[p] = P[p];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushup(p);
}

int query(int l, int r, int p = 1, int pl = 1, int pr = n) {
    if (l <= pl and pr <= r) {
        return t[p];
    }
    int mid = (l + r) >> 1, ans = 0;
    if (l <= mid)
        ans ^= query(l, r, ls(p), l, mid);
    if (mid < r)
        ans ^= query(l, r, rs(p), mid + 1, r);
    return ans;
}

void modify(int v, int i, int p = 1, int l = 1, int r = n) {
    if (l >= r) {
        t[p] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid)
        modify(v, i, ls(p), l, mid);
    else
        modify(v, i, rs(p), mid + 1, r);
    pushup(p);
}

signed main() {
    freopen("in","r",stdin);
    scanf("%u%u", &n, &q);
    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%u%u", &c, &P[i]);
        for (int j = 1; j <= c; j++) {
            int tmp;
            scanf("%u%*u", &tmp);
            xo[i] ^= tmp;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int op;
        scanf("%u",&op);
        if (op==1)
        {
            int l,v;
            scanf("%u%u", &l, &v);
            modify(v,l);
        }else{
            int l,r,x;
            scanf("%u%u%u", &l,&r, &x);
            printf("%u\n",x^query(l,r));
        }
        
    }
    
}