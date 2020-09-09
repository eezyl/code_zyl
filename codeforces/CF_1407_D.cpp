// =====================================================
//   File    :   main.cpp
//   Author  :   eezyl
//   Synopsis:   codeforces/atcoder template
//   Address :   https://codeforces.com/problemset/problem/1407/D
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

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    F0R(i, n)
        cin >> h[i];
    vector<int> ans(n, n);
    vector<int> st;
    vector<int> st2;
    st.pb(n-1);
    st2.pb(n-1);
    ans[n-1] = 0;
    for (int i = n-2; ~i; --i) {
        int temp = ans[i+1];
        while (!st.empty() && h[i] >= h[st.back()]) {
            ckmin(temp, ans[st.back()]);
            if (h[i] != h[st.back()]) {
                st.pop_back();
                if (!st.empty())
                    ckmin(temp, ans[st.back()]);
            } else
                st.pop_back();
        }

        st.pb(i);

        while (!st2.empty() && h[i] <= h[st2.back()]) {
            ckmin(temp, ans[st2.back()]);
            if (h[i] != h[st2.back()]) {
                st2.pop_back();
                if (!st2.empty())
                    ckmin(temp, ans[st2.back()]);
            } else
                st2.pop_back();
        }

        st2.pb(i);

        ans[i] = temp+1;


    }
    //for (int i = 0; i < n; ++i)
    //    cout << ans[i] << endl;
    cout << ans[0] << endl;
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
