#include <bits/stdc++.h>
using namespace std;
#define N 18
#define ll long long
#define P 998244353
int a[N][26];
int n;
void get(int (&p)[26]) {
    char c;
    while ((c = getchar()) < 'a')
        ;
    do {p[c - 'a']++;}
    while ((c = getchar()) >= 'a');
        
}
int rng[N];

int solve(){
    ll ans=1;
    for (int i = 1; i <= n/2; i++)
    {
        int l=rng[i],r=rng[n-i+1];
        ll per=0;
        for (int c = 0; c < 26; c++)
        {
            per+=1ll*a[l][c]*a[r][c]%P;
            per%=P;
        }
        if (per==0){
            return 0;
        }
        ans=ans*per%P;
    }
    if (n&1){
        ll per=0;
        for (int c = 0; c < 26; c++)
        {
            per=(per+a[rng[n/2+1]][c])%P;
        }
        ans=ans*per%P;
    }
    return ans;
}
signed main() {
    freopen("in","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        rng[i] = i;
        get(a[i]);
        
    }
    ll ans=0;
    do {
        ans=(ans+solve())%P;
    } while (next_permutation(rng + 1, rng + n + 1));
    printf("%lld",ans);
}