// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :
//   Date    :   2020/08/21
// =====================================================
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef vector<vi> vvi;

#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { return b ? "true" : "false"; }
str ts(vector<bool> v) { str res; F0R(i,sz(v)) res += char('0'+v[i]); return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res; F0R(i,SZ) res += char('0'+b[i]); return res; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))

const ll MOD = 1e9+7; // 998244353;
const int MX = 3e5+5;

ll n;
vvi adj;
vll w;
int endnode, far;
void dfs(int u, int p, int k) {
    if (far < k) {
        far = k;
        endnode = u;
    }
    for (auto& v: adj[u]) if (v != p) {
        dfs(v, u, k+1);
    }
}

ll dfs2(int u, int p) {
    ll d = 1;
    for (auto& v: adj[u]) if (v != p) {
        d += dfs2(v, u);
    }
    if (d!=n)
        w.push_back(d*(n-d));

    return d;
}

void solve() {

    cin >> n;
    adj.clear();
    adj.resize(n+1);
    F0R(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    far = 0;
    dfs(1, 0, 0);
    w.clear();
    dfs2(endnode, 0);

    //cout << w.size() << endl;

    sort(rall(w));
    int m;
    cin >> m;
    vector<ll> p(m);
    F0R(i, m)
        cin >> p[i];
    sort(rall(p));

    ll ans = 0;
    if (n-1 >= m) {
        F0R(i, m)
            ans = (ans + w[i] * p[i]) % MOD;
        FOR(i, m, n-1)
            ans = (ans + w[i]) % MOD;
        cout << ans%MOD << endl;
    } else {
        ll ps = 1;
        FOR(i, 0, m-n+2)
            ps = ps*p[i]%MOD;
        ans = w[0]*ps%MOD;
        FOR(i, 1, n-1)
            ans = (ans + w[i]*p[i+m-n+1]) % MOD;
        cout << ans << endl;
    }

}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define LOCAL
#ifdef LOCAL
freopen("data.in", "r", stdin);
while (!feof(stdin)) {
#endif // LOCAL

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
