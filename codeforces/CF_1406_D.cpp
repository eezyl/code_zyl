// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template v2
//   Address :   https://codeforces.com/problemset/problem/1406/D
//   Date    :   2020/09/12
// =====================================================
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<db> vdb;
typedef vector<string> vs;
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
string ts(char c) { return string(1,c); }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
string ts(bool b) { return b ? "true" : "false"; }
string ts(vector<bool> v) { string res; F0R(i,sz(v)) res += char('0'+v[i]); return res; }
template<size_t SZ> string ts(bitset<SZ> b) { string res; F0R(i,SZ) res += char('0'+b[i]); return res; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))

const ll MOD = 1e9+7; // 998244353;
const int MX = 1e5+5;

// BIT
int tree[1];
int sum(int k, int a = 0) {
    while (k >= 1) { a += tree[k]; k -= k&-k; }
    return a; }
void add(int k, int x) {
    while (k <= MX) { tree[k] += x; k += k&-k; }
}

int find(vi& ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}

ll out(ll a, ll b) {
    return ceil((double)(a+b)/2.0);
}

void solve()
{
    int n;
    cin >> n;
    vll a(n+1);
    FOR(i,1, n+1)
        cin >> a[i];
    ll sum = 0;
    FOR(i, 2, n+1) {
        if (a[i]-a[i-1] > 0)
            sum+= a[i]-a[i-1];
    }
    ll a1 = a[1];
    cout << out(a1, sum) << endl;
    for (int i = n; i > 1; --i) {
        a[i] = a[i]-a[i-1];
    }
    int q;
    cin >> q;
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        if (l == 1)
            a1 += x;
        else {
            if (a[l] > 0)
                sum -= a[l];
            a[l] += x;
            if (a[l] > 0)
                sum += a[l];
        }
        if (r != n) {
            if (a[r+1] > 0)
                sum -= a[r+1];
            a[r+1] -= x;
            if (a[r+1] > 0)
                sum += a[r+1];
        }
        //for (int i = 1; i <= n; ++i)
        //    cout << a[i] << " ";
        //cout << endl;
        cout << out(a1, sum) << endl;
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
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef LOCAL
}
printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
