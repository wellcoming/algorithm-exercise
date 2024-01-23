#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 1000
#define P
using namespace std;
int n,q;
int A,B,L,R;
struct trans{
    int c,f;
    bool operator<(const trans& o) const{
        return f<o.f;
    }
}t[N];
struct pos2{
    int a,b;
    bool operator==(const pos2& p)const{
        return (a==p.a&&b==p.b) or (a==p.b&&b==p.a);
    }
};
struct pos2hash{
    size_t operator()(const pos2& p)const{
        return hash<int>()(p.a)^hash<int>()(p.b);
    }
};

unordered_map<pos2,int,pos2hash> dp;

void init(){
    dp.clear();
}

int main(){
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; ++i) scanf("%d",&t[i].c);
    for (int i = 1; i <= n; ++i) scanf("%d",&t[i].f);
    sort(t+1,t+n+1);





}
