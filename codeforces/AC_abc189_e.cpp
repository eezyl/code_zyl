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
    int N;
    cin >> N;
    vll X(N+1), Y(N+1);
    F0R(i, N)
        cin >> X[i+1] >> Y[i+1];

    int M;
    cin >> M;
    vll op(M+1), p(M+1);
    F0R(i, M) {
        int n;
        cin >> n;
        if (n == 3 || n == 4)
            cin >> p[i];
        op[i] = n;
    }

    int Q;
    cin >> Q;
    multimap<int, array<int, 2> > mm;
    F0R(i, Q) {
        int a, b;
        cin >> a >> b;
        mm.insert({a, {b, i}});
    }

    int pi = 0;
    ll cur_m[3][3] = {0};
    cur_m[0][0] = 1;
    cur_m[1][1] = 1;
    cur_m[2][2] = 1;

    vll ans_X(Q, 0), ans_Y(Q, 0);
    for (auto& q: mm) {

        for (; pi < M && pi < q.first; ++pi) {
            ll op_m[3][3] = {0};
            if (op[pi] == 1) {
                op_m[0][1] = 1;
                op_m[1][0] = -1;
                op_m[2][2] = 1;
            } else if (op[pi] == 2) {
                op_m[0][1] = -1;
                op_m[1][0] = 1;
                op_m[2][2] = 1;
            } else if (op[pi] == 3) {
                op_m[0][0] = -1; op_m[0][2] = p[pi]*2;
                op_m[1][1] = 1;
                op_m[2][2] = 1;
            } else if (op[pi] == 4) {
                op_m[0][0] = 1;
                op_m[1][1] = -1; op_m[1][2] = p[pi]*2;
                op_m[2][2] = 1;
            }
            ll new_m[3][3] = {0};
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        new_m[i][j] += op_m[i][k] * cur_m[k][j];
                    }
                }
            }
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cur_m[i][j] = new_m[i][j];
                }
            }
        }
/*
        cout << "aaa" << q.first << " " << q.second[0] <<" "<<q.second[1]<< endl;
        cout << X[q.second[0]] << " " << Y[q.second[0]] << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << cur_m[i][j] << " ";
            }
            cout << endl;
            }
*/
        ans_X[q.second[1]] = cur_m[0][0]*X[q.second[0]] + cur_m[0][1]*Y[q.second[0]] + cur_m[0][2];
        ans_Y[q.second[1]] = cur_m[1][0]*X[q.second[0]] + cur_m[1][1]*Y[q.second[0]] + cur_m[1][2];
    }



    F0R(i, Q) {
        cout << ans_X[i] << " " << ans_Y[i] << endl;
    }
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
