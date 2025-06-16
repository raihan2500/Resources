#include<bits/stdc++.h>
using namespace std;
 
//using u128 = __uint128_t;
#define int                 long long
 
#define endl                "\n"
#define yes                 cout<<"YES\n"
#define no                  cout<<"NO\n"
#define nl                  cout<<"\n"
#define cnl                 clog<<"\n"
 
#define lin(n)              int n;cin>>n;
#define vin                 vector<int>
#define pr                  pair<int, int>
#define pp                  pop_back()
#define pb(n)               push_back(n)
#define all(x)              x.begin(),x.end()
#define ppfr(v)             v.erase(v.begin());
#define sum_all(v)          accumulate(all(v), 0ll)
 
#define forn(i,n)           for(int i = 0; i < n; i++)
#define Forn(i,n)           for(int i = 1; i <= n; i++)
#define rforn(i,n)          for(int i = n - 1; i >= 0; i--)
#define print(arr)          for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)          for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;
 
#define _log2(n)            31 - __builtin_clz(n)
#define pop_count(n)        __builtin_popcount(n)
 
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y)            uniform_int_distribution<int>(x,y)(rng)
 
#ifdef DEBUG
#include<algo/debug.h>
#else
#   define clog if (0) cerr
#   define NB 2500
#   define db(...) "" 
#endif
 
// const int M = 998244353;
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;
 
int n, m, v[N], t[N];
vin pos[N];
 
 
void update(int i, int x){
    for(; i <= n; i += i & -i)t[i] += x;
}
 
void update(int i){
    update(i, -1);
    pos[v[i]].pop_back();
    if(pos[v[i]].size())update(pos[v[i]].back(), 1);
}
 
int query(int i){
    if(i < 0)return 0;
    int ans = 0;
    for(; i; i -= i & -i)ans += t[i];
    return ans;
}
 
int query(int l, int r){
    return query(r) - query(l - 1);
}
 
void _(){
    int q;
    cin >> n >> q;
    map<int, int> mp;
    for(int i = 1; i <= n; i++)cin >> v[i], mp[v[i]];
    m = 0;
    for(auto &i : mp)i.second = ++m;
    for(int i = 1; i <= n; i++)v[i] = mp[v[i]]; 
    for(int i = 1; i <= n; i++){
        pos[v[i]].push_back(i);
    }
 
    for(int i = 1; i <= n; i++)reverse(all(pos[i]));
 
 
    for(int i = 1; i <= n; i++){
        if(pos[i].size())
            update(pos[i].back(), 1);
    }
 
    struct Q{
        int id, l, r;
        void show(){
            clog << id <<" " << l <<" " << r << endl;
        }
    };
    vector<Q> qr(q + 1);
    for(int i = 1; i <= q; i++){
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(all(qr), [&](Q &a, Q &b){
        return a.l < b.l;
    });
 
    qr[0].l = qr[0].r  = 1;
 
    int ans[q + 1];
    for(int i = 1; i <= q; i++){
        while(qr[i].l > qr[i - 1].l){
            update(qr[i - 1].l++);
        }
        ans[qr[i].id] = query(qr[i].r);
    }
 
    for(int  i = 1; i <= q; i++)cout << ans[i] <<"\n";
}
 
int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    int test = 1;  
    // cin>>test;
    for(int i = 1; i <= test; i++){
        // cout << "Case " << i <<": ";
        _();
    }
    return 0;
}