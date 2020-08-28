// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :   https://codeforces.com/contest/1401/problem/E
//   Date    :   2020/08/25
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
const int MX = 1e6+1;

int tree[MX+5];

int sum(int k) {
    int a = 0;
    while (k >= 1) {
        a += tree[k];
        k -= k&-k;
    }
    return a;
}

void add(int k, int x) {
    while (k <= MX) {
        tree[k] += x;
        k += k&-k;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    ll ans = 1;

    vector<pair<int, int> > qs(MX+5);
    vvi ver(MX+5);

    F0R(i, n) {
        int y, l, r;
        cin >> y >> l >> r;
        ++y; ++l; ++r;
        qs[y] = make_pair(l, r);
        if (l == 1 && r == MX)
            ++ans;
    }
    //cout << "aaa" << endl;
    F0R(i, m) {
        int x, b, t;
        cin >> x >> b >> t;
        ++x; ++b; ++t;
        ver[b].pb(x);
        ver[t+1].pb(-x);
        if (b == 1 && t == MX)
            ++ans;
    }
    //cout << "bbb" << endl;
    FOR(y, 1, MX+1) {
        //cout << y << endl;
        for (int &x: ver[y]) {
            //cout << x << endl;
            if (x > 0)
                add(x, 1);
            else
                add(-x, -1);
        }
        //cout << y << endl;
        auto &p = qs[y];
        if (p.second != 0) {
            ans += sum(p.second) - sum(p.first-1);
        }
    }

    cout << ans << endl;
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
    //cin >> t;
    while (t--) {
        solve();
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
