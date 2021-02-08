// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template v2
//   Address :
//   Date    :   2021/01/16
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
typedef vector<pll> vpl;
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

const ll MOD = 998244353; // 998244353;
const int MX = 1e5+5;

// BIT
int tree[1];
int sum(int k, int a = 0) {
    while (k >= 1) { a += tree[k]; k -= k&-k; }
    return a; }
void add(int k, int x) {
    while (k <= MX) { tree[k] += x; k += k&-k; }
}
// Disjoint Set
int find(vi& ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
void join(vector<int> &ds, int a, int b) {
    int i = find(ds, a), j = find(ds, b);
    if (i != j) {
        if (ds[i] > ds[j]) swap(i, j);
        ds[i] += ds[j]; ds[j] = i; }
}



void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vld C(N+1, 0);
    vld X(N+1, 0);
    F0R(i, K) {
        int k;
        cin >> k;
        X[k] = 1.0;
    }

    ld sum_c = 0.0;
    ld sum_x = 0.0;
    for (int i = N-1; i >= 0; --i) {

        //cout << sum_c << " " << sum_x << endl;
        if (X[i] == 0) {
            C[i] = sum_c/M+1;
            X[i] = sum_x/M;
        }
        sum_c += C[i];
        sum_x += X[i];
        if (i+M <= N) {
            sum_c -= C[i+M];
            sum_x -= X[i+M];
        }
    }
    if (fabs(X[0]-1) < 1e-6)
        cout << -1 << endl;
    else
        printf("%.4Lf\n", C[0] / (1-X[0]));
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
