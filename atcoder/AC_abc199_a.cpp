// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template v2.2
//   Address :
//   Date    :   2021/02/27
// =====================================================
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<db> vdb;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pdb> vpdb;
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

#define rep(i,x,y) for (int i = (x); i < (y); ++i)
#define repr(i,y,x) for (int i = (y-1); i >= (x); --i)
#define trav(a,x) for (auto& a: x)

const ll INF = LLONG_MAX;
const ld PI = acos((ld)-1);
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

// TO_STRING
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
string ts(bool b) { return b ? "true" : "false"; }
string ts(vector<bool> v) { string res; rep(i,0,sz(v)) res += char('0'+v[i]); return res; }
template<size_t SZ> string ts(bitset<SZ> b) { string res; rep(i,0,SZ) res += char('0'+b[i]); return res; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))

// BIT
const int TX = 1;
int tree[1];
int sum(int k, int a = 0) { while (k >= 1) { a += tree[k]; k -= k&-k; } return a; }
void add(int k, int x) { while (k <= TX) { tree[k] += x; k += k&-k; } }
// Disjoint Set
int find(vi& ds, int i) { return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]); }
void join(vector<int> &ds, int a, int b) {
    int i = find(ds, a), j = find(ds, b);
    if (i != j) {
        if (ds[i] > ds[j]) swap(i, j);
        ds[i] += ds[j]; ds[j] = i; }
}




const ll MOD = 998244353; // 998244353;
const int MX = 1e5+5;

// =====================================================
// Given ax+by=gcd(a,b),
// return value is gcd(a, b) and x, y (paseed by reference)
// =====================================================
template<class T>
T exgcd(T a, T b, T &x, T &y)
{
    if (!b) { x = 1; y = 0; return a; }
    T g = exgcd(b, a%b, y, x); y -= (a/b) *x; return g;
}

// =====================================================
// Solve ax+by=c, return false if there is no solution
// =====================================================
template<class T>
bool exgcd(T a, T b, T c, T &x0, T &y0, T &g)
{
    g = exgcd(abs(a), abs(b), x0, y0);
    if (c % g) return false;
    x0 *= c/g;
    y0 *= c/g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a*a+b*b < c*c)
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
//#define LOCAL
#ifndef LOCAL
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
#ifdef LOCAL
    freopen("data.in", "r", stdin); while (!feof(stdin)) {
#endif // LOCAL

    int t = 1;
    //cin >> t;
    while (t--) solve();

#ifdef LOCAL
    }    printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif // LOCAL
    return 0;
}
