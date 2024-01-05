#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 200005
#define P
using namespace std;
int n,nn,hn,m,b;
int a[N],sa[N];
int ans[N];
int t[N];

struct Query{
    int l,r,k,id;
}q[N];

void add(int x,int v){
    for (int i = x; i <= nn; i+=i&-i) t[i]+=v;
}
int query(int k){
    int c=0;
    for (int i = hn;i>0; i>>=1) {
        if (c+i>nn)continue;
        if (k-t[c+i]>0){
            k-=t[c+i];
            c+=i;
        }
    }
    return c+1;
}
int highbit(int n) {
    if (n == 0) return 0;
    return 1 << (31 - __builtin_clz(n));
}
signed main(){
    scanf("%d%d",&n,&m);
    b=ceil(sqrt(n));
    for (int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);
    memcpy(sa,a,(n+1)*(sizeof *a));
    sort(sa+1,sa+n+1);
    nn=unique(sa+1,sa+n+1)-sa-1;
    hn= highbit(nn);
    for (int i = 1; i <= n; ++i) {
        a[i]=lower_bound(sa+1,sa+nn+1,a[i])-sa;
    }


    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
        q[i].id=i;
    }
    sort(q+1,q+m+1,[](const Query& l, const Query& r){
        if (l.l / b == r.l / b)
            return (l.l / b & 1) ? l.r < r.r : l.r > r.r;
        return l.l < r.l;
    });
    int l=1,r=0;
    for (int i = 1; i <= m; ++i) {
        while (l<q[i].l)add(a[l++],-1);
        while (r>q[i].r)add(a[r--],-1);
        while (l>q[i].l)add(a[--l],1);
        while (r<q[i].r)add(a[++r],1);
        ans[q[i].id]=sa[query(q[i].k)];
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n",ans[i]);
    }
}
