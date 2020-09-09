// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :   https://codeforces.com/problemset/problem/1407/C
//   Date    :   2020/09/08
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
const int MX = 1e5+5;

int tree[1];

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

vi adj[MX];
int depth[MX];
int diam;
int dfs(int u, int p) {
    int len = 0;
    for (int &v:adj[u]) if (v != p) {
        depth[v] = depth[u]+1;
        int cur = 1+dfs(v, u);
        ckmax(diam, cur+len);
        ckmax(len, cur);
    }
    return len;
}

int dp[205][205][205] = {0};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    vector<int> b(n+1, 0);

    int count = n-1;
    while (count--) {
        int x, y;
        for (int i = 1; i <= n; ++i) if (!b[i]) {
            x = i;
            break;
        }
        for (int i = x+1; i <= n; ++i) if (!b[i]) {
            y = i;
            break;
        }
        int ans1, ans2;
        printf("? %d %d\n", x, y);
        fflush(stdout);
        scanf("%d", &ans1);
        printf("? %d %d\n", y, x);
        fflush(stdout);
        scanf("%d", &ans2);
        if (ans1 > ans2) {
            a[x] = ans1;
            b[x] = 1;
        } else {
            a[y] = ans2;
            b[y] = 1;
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i <= n; ++i) {
        sum1 += i;
        sum2 += a[i];
    }
    for (int i = 1; i <= n; ++i) if (!b[i]) {
        a[i] = sum1-sum2;
    }
    printf("! ");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    fflush(stdout);
}


int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
